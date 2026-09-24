/*
 * Recursion / backtracking patterns for FAANG interviews
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void subsetsDfs(int i, const std::vector<int>& nums,
                std::vector<int>& path,
                std::vector<std::vector<int>>& ans) {
    if (i == static_cast<int>(nums.size())) {
        ans.push_back(path);
        return;
    }
    // skip
    subsetsDfs(i + 1, nums, path, ans);
    // take
    path.push_back(nums[i]);
    subsetsDfs(i + 1, nums, path, ans);
    path.pop_back();
}

std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    std::vector<int> path;
    subsetsDfs(0, nums, path, ans);
    return ans;
}

void permuteDfs(std::vector<int>& nums, int start,
                std::vector<std::vector<int>>& ans) {
    if (start == static_cast<int>(nums.size())) {
        ans.push_back(nums);
        return;
    }
    for (int i = start; i < static_cast<int>(nums.size()); i++) {
        std::swap(nums[start], nums[i]);
        permuteDfs(nums, start + 1, ans);
        std::swap(nums[start], nums[i]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int> nums) {
    std::vector<std::vector<int>> ans;
    permuteDfs(nums, 0, ans);
    return ans;
}

void comboDfs(int start, int remain, const std::vector<int>& cand,
              std::vector<int>& path,
              std::vector<std::vector<int>>& ans) {
    if (remain == 0) {
        ans.push_back(path);
        return;
    }
    for (int i = start; i < static_cast<int>(cand.size()); i++) {
        if (cand[i] > remain) break;
        path.push_back(cand[i]);
        comboDfs(i, remain - cand[i], cand, path, ans);  // reuse allowed
        path.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> ans;
    std::vector<int> path;
    comboDfs(0, target, candidates, path, ans);
    return ans;
}

void genParens(int open, int close, int n, std::string& cur,
               std::vector<std::string>& ans) {
    if (static_cast<int>(cur.size()) == 2 * n) {
        ans.push_back(cur);
        return;
    }
    if (open < n) {
        cur.push_back('(');
        genParens(open + 1, close, n, cur, ans);
        cur.pop_back();
    }
    if (close < open) {
        cur.push_back(')');
        genParens(open, close + 1, n, cur, ans);
        cur.pop_back();
    }
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> ans;
    std::string cur;
    genParens(0, 0, n, cur, ans);
    return ans;
}

int main() {
    auto s = subsets({1, 2});
    std::cout << s.size() << "\n";  // 4

    auto p = permute({1, 2, 3});
    std::cout << p.size() << "\n";  // 6

    auto c = combinationSum({2, 3, 6, 7}, 7);
    std::cout << c.size() << "\n";  // 2: [2,2,3] and [7]

    auto g = generateParenthesis(3);
    for (auto& x : g) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}
