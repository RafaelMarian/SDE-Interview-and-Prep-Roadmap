# 97. Interleaving String

**Lists:** Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

Given strings `s1`, `s2`, and `s3`, return `true` if `s3` is formed by an interleaving of `s1` and `s2`.

## Intuition

`dp[i][j]` = whether first `i` chars of `s1` and first `j` chars of `s2` can form first `i+j` chars of `s3`. Transition from `(i-1,j)` or `(i,j-1)` if next char matches.

## Approach

1. If `s1.size() + s2.size() != s3.size()`, return false.
2. 2D bool table or 1D rolled array of size `m+1`.
3. `dp[0][0]=true`; fill using character equality checks.
4. Return `dp[m][n]`.

## Complexity

- **Time:** O(m × n)
- **Space:** O(n) with rolling array

## C++ Solution

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != (int)s3.size()) return false;
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0) continue;
                bool ok = false;
                if (i > 0 && s1[i - 1] == s3[i + j - 1]) ok = ok || dp[j];
                if (j > 0 && s2[j - 1] == s3[i + j - 1]) ok = ok || dp[j - 1];
                dp[j] = ok;
            }
        }
        return dp[n];
    }
};
```
