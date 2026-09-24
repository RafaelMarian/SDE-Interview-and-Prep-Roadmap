# 221. Maximal Square

**Lists:** Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

Given an `m x n` binary matrix `matrix`, return the area of the largest square containing only `1`s.

## Intuition

`dp[i][j]` = side length of largest square ending at `(i,j)`. If cell is `1`, `dp[i][j] = 1 + min(top, left, top-left)`. Track max side.

## Approach

1. Use one row `dp` plus variable `prevDiag` for top-left neighbor.
2. For each `1`, update with min of neighbors; update `sideMax`.
3. Return `sideMax * sideMax`.

## Complexity

- **Time:** O(m × n)
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n + 1, 0);
        int sideMax = 0, prev = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int temp = dp[j + 1];
                if (matrix[i][j] == '1') {
                    dp[j + 1] = 1 + min({dp[j], dp[j + 1], prev});
                    sideMax = max(sideMax, dp[j + 1]);
                } else {
                    dp[j + 1] = 0;
                }
                prev = temp;
            }
        }
        return sideMax * sideMax;
    }
};
```
