# 63. Unique Paths II

**Lists:** Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

You are given an `m x n` integer array `grid`. A robot is initially located at the top-left corner. The robot can only move down or right. An obstacle and space are marked with `1` and `0` respectively. Return the number of unique paths to the bottom-right corner.

## Intuition

Same as Unique Paths I, but cells with obstacles contribute 0 paths. `dp[j]` = ways to reach column j in current row.

## Approach

1. If start is obstacle, return 0.
2. Initialize first row/column in `dp` with prefix logic respecting obstacles (or use 2D then compress).
3. For each cell: if obstacle, `dp[j]=0`; else `dp[j] += dp[j-1]` (with first row/col handled).

## Complexity

- **Time:** O(m × n)
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;
        vector<unsigned long long> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j]) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return (int)dp[n - 1];
    }
};
```
