# 72. Edit Distance

**Lists:** Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

Given two strings `word1` and `word2`, return the minimum number of operations required to convert `word1` to `word2`. You may insert, delete, or replace a character.

## Intuition

Let `dp[i][j]` = edit distance between prefixes of length `i` and `j`. If chars match, no cost; else 1 + min(insert, delete, replace).

## Approach

1. `dp[i][0]=i`, `dp[0][j]=j`.
2. Fill: if `word1[i-1]==word2[j-1]`, `dp[i][j]=dp[i-1][j-1]`; else `dp[i][j]=1+min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])`.
3. Use two rows for space.

## Complexity

- **Time:** O(m × n)
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> prev(n + 1), cur(n + 1);
        for (int j = 0; j <= n; ++j) prev[j] = j;
        for (int i = 1; i <= m; ++i) {
            cur[0] = i;
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = prev[j - 1];
                } else {
                    cur[j] = 1 + min({prev[j], cur[j - 1], prev[j - 1]});
                }
            }
            prev.swap(cur);
        }
        return prev[n];
    }
};
```
