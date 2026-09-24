/*
 * Recursion & Backtracking — subsets, permutations, combination sum, N-Queens (n=4)
 * LeetCode: 78, 46, 39, 51
 */

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <cmath>

// LeetCode 78 — subsets
std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    int n = static_cast<int>(nums.size());
    std::function<void(int)> dfs = [&](int i) {
        if (i == n) {
            res.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        dfs(i + 1);
        path.pop_back();
        dfs(i + 1);
    };
    dfs(0);
    return res;
}

// LeetCode 46 — permutations
std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    std::vector<bool> used(nums.size(), false);
    std::function<void()> dfs = [&]() {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            dfs();
            path.pop_back();
            used[i] = false;
        }
    };
    dfs();
    return res;
}

// LeetCode 39 — combination sum (reuse allowed)
std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    std::function<void(int, int)> dfs = [&](int start, int remain) {
        if (remain == 0) {
            res.push_back(path);
            return;
        }
        if (remain < 0) return;
        for (int i = start; i < static_cast<int>(candidates.size()); i++) {
            path.push_back(candidates[i]);
            dfs(i, remain - candidates[i]);
            path.pop_back();
        }
    };
    dfs(0, target);
    return res;
}

// N-Queens — print one solution board for n=4 (LeetCode 51 simplified)
bool solveNQueensBoard(int n, std::vector<std::string>& board) {
    board.assign(n, std::string(n, '.'));
    std::vector<int> col(n, -1);

    auto safe = [&](int row, int c) {
        for (int r = 0; r < row; r++) {
            int cc = col[r];
            if (cc == c) return false;
            if (row - r == std::abs(c - cc)) return false;
        }
        return true;
    };

    std::function<bool(int)> dfs = [&](int row) -> bool {
        if (row == n) return true;
        for (int c = 0; c < n; c++) {
            if (!safe(row, c)) continue;
            col[row] = c;
            board[row][c] = 'Q';
            if (dfs(row + 1)) return true;
            board[row][c] = '.';
        }
        return false;
    };
    return dfs(0);
}

int main() {
    std::vector<int> nums{1, 2, 3};
    auto sub = subsets(nums);
    std::cout << "subsets count: " << sub.size() << " (expect 8)\n";

    auto perms = permute(nums);
    std::cout << "permutations count: " << perms.size() << " (expect 6)\n";

    std::vector<int> cand{2, 3, 6, 7};
    auto cs = combinationSum(cand, 7);
    std::cout << "combinationSum(7) count: " << cs.size() << "\n";

    std::vector<std::string> board;
    if (solveNQueensBoard(4, board)) {
        std::cout << "N-Queens n=4:\n";
        for (const auto& row : board) std::cout << row << '\n';
    }
    return 0;
}
