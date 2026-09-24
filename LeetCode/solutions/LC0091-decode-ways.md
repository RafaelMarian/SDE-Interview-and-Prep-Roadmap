# 91. Decode Ways

**Lists:** Blind 75, Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

A message containing letters `A-Z` is encoded to numbers `1-26`. Given a string `s` of digits, return the number of ways to decode it.

## Intuition

`dp[i]` = ways to decode prefix ending at `i`. Single digit `1-9` or two digits `10-26` if valid and no leading zero on two-digit chunk.

## Approach

1. `dp[n] = 1` (empty suffix).
2. Walk from end: if `s[i] != '0'`, add `dp[i+1]`; if two-digit valid, add `dp[i+2]`.

## Complexity

- **Time:** O(n)
- **Space:** O(n) or O(1) with rolling

## C++ Solution

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i + 1];
            if (i + 1 < n) {
                int two = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (two >= 10 && two <= 26) dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};
```
