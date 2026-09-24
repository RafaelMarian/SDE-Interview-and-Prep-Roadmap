# 62. Unique Paths

**Lists:** Blind 75, Top Interview 150  
**Topic:** 2D DP  
**Difficulty:** Medium  

## Problem

Robot on `m x n` grid top-left to bottom-right, only right or down. Return number of unique paths.

## Intuition

Paths to `(i,j)` = paths from top + paths from left. First row/column are all 1.

## Approach

Single row DP of size `n`, update per row.

## Complexity

- **Time:** O(m · n)
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[j] += dp[j - 1];
        return dp[n - 1];
    }
};
```
