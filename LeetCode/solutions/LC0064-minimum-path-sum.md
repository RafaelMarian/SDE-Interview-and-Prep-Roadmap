# 64. Minimum Path Sum

**Lists:** Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

Given a `m x n` grid filled with non-negative numbers, find a path from top-left to bottom-right which minimizes the sum of all numbers along its path. You may only move down or right.

## Intuition

`dp[i][j]` = min cost to reach `(i,j)` = grid value + min(top, left). Can roll to one row.

## Approach

1. `dp[j]` initialized from first row prefix sums.
2. For rows `1..m-1`, update `dp[0] += grid[i][0]`, then `dp[j] = grid[i][j] + min(dp[j], dp[j-1])`.
3. Return `dp[n-1]`.

## Complexity

- **Time:** O(m × n)
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n);
        dp[0] = grid[0][0];
        for (int j = 1; j < n; ++j) dp[j] = dp[j - 1] + grid[0][j];
        for (int i = 1; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j)
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
        }
        return dp[n - 1];
    }
};
```
