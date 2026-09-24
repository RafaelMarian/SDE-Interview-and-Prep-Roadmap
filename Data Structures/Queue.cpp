/*
 * Queue / Deque patterns for FAANG interviews
 * - BFS shortest path in unweighted grid
 * - Sliding window maximum via monotonic deque
 */

#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <string>

// Shortest path in binary grid (0 = empty, 1 = blocked). 4-directional.
int shortestPathBinaryMatrix(std::vector<std::vector<int>> grid) {
    int n = static_cast<int>(grid.size());
    if (n == 0 || grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
    if (n == 1) return 1;

    static const int dr[] = {-1, 1, 0, 0};
    static const int dc[] = {0, 0, -1, 1};

    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1;  // mark visited / store distance in-place
    int dist = 1;

    while (!q.empty()) {
        int sz = static_cast<int>(q.size());
        while (sz--) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] == 1)
                    continue;
                if (nr == n - 1 && nc == n - 1) return dist + 1;
                grid[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
        dist++;
    }
    return -1;
}

std::vector<int> maxSlidingWindow(const std::vector<int>& a, int k) {
    std::deque<int> dq;  // indices, values decreasing
    std::vector<int> res;
    for (int r = 0; r < static_cast<int>(a.size()); r++) {
        while (!dq.empty() && a[dq.back()] <= a[r]) dq.pop_back();
        dq.push_back(r);
        if (dq.front() <= r - k) dq.pop_front();
        if (r >= k - 1) res.push_back(a[dq.front()]);
    }
    return res;
}

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };
    std::cout << shortestPathBinaryMatrix(grid) << "\n";  // 4

    auto mx = maxSlidingWindow({1, 3, -1, -3, 5, 3, 6, 7}, 3);
    for (int x : mx) std::cout << x << " ";  // 3 3 5 5 6 7
    std::cout << "\n";
    return 0;
}
