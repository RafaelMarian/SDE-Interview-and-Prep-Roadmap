# 5. Longest Palindromic Substring

**Lists:** Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

Given a string `s`, return the longest palindromic substring in `s`.

## Intuition

Expand around every center (odd and even). Alternatively `dp[i][j]` = true if `s[i..j]` is palindrome when ends match and inner is palindrome.

## Approach

1. For each center `c` from `0` to `2n-1`, expand while characters match.
2. Track longest `[start, len]`.
3. Return substring.

## Complexity

- **Time:** O(n²)
- **Space:** O(1) for expand; O(n²) for table DP

## C++ Solution

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int bestStart = 0, bestLen = 1;
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
            }
            int len = r - l - 1;
            if (len > bestLen) {
                bestLen = len;
                bestStart = l + 1;
            }
        };
        for (int i = 0; i < n; ++i) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(bestStart, bestLen);
    }
};
```
