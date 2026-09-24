# 115. Distinct Subsequences

**Lists:** Top Interview 150  
**Topic:** 2D DP  
**Difficulty:** Hard  

## Problem

Given two strings `s` and `t`, return the number of distinct subsequences of `s` which equal `t`.

## Intuition

`dp[i][j]` = number of ways to form `t[0..j-1]` from `s[0..i-1]`. If `s[i-1] != t[j-1]`, skip `s[i-1]`; if equal, add ways without using `s[i-1]` plus ways using it.

## Approach

1. `dp[i][0] = 1` for all `i` (empty `t` matched once).
2. For `i` from 1 to m, `j` from 1 to n: if chars differ, `dp[i][j]=dp[i-1][j]`; else `dp[i][j]=dp[i-1][j]+dp[i-1][j-1]`.
3. Use `unsigned long long` or `uint64_t`; answer fits in LeetCode tests with 64-bit.

## Complexity

- **Time:** O(m × n)
- **Space:** O(n) with one row

## C++ Solution

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) dp[j] += dp[j - 1];
            }
        }
        return (int)dp[n];
    }
};
```
