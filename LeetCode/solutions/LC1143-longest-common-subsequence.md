# 1143. Longest Common Subsequence

**Lists:** Blind 75, Top Interview 150  
**Topic:** 2D DP  
**Difficulty:** Medium  

## Problem

Given two strings `text1` and `text2`, return the length of their longest common subsequence.

## Intuition

If last chars match, LCS extends by 1; else take max of dropping one char from either string.

## Approach

2D DP: `dp[i][j]` for prefixes `text1[0..i)` and `text2[0..j)`. Can compress to 1D row.

## Complexity

- **Time:** O(m · n)
- **Space:** O(m · n), or O(min(m,n)) rolling

## C++ Solution

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        return dp[m][n];
    }
};
```
