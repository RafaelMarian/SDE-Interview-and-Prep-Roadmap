# 139. Word Break

**Lists:** Blind 75, Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

Given string `s` and dictionary `wordDict`, return `true` if `s` can be segmented into space-separated words from the dictionary (reuse allowed).

## Intuition

`dp[i]` = can prefix `s[0..i)` be segmented? For each `i`, try every word ending at `i`.

## Approach

1. Put dictionary in hash set.
2. `dp[0] = true`.
3. For `i` from 1 to `n`, for `j` from 0 to `i-1`, if `dp[j]` and `s.substr(j,i-j)` in set, `dp[i]=true`.

## Complexity

- **Time:** O(n² · L) worst case (substr); can optimize with trie.
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
```
