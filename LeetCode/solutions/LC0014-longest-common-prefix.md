# LC 14. Longest Common Prefix

**Lists:** Top 150
**Topic:** String
**Difficulty:** Easy

## Problem
Given an array of strings `strs`, return the longest common prefix string shared by all strings. If none exists, return `""`.

## Intuition
Compare characters column by column across all strings until a mismatch or a string ends.

## Approach
1. If `strs` is empty, return `""`.
2. For index `i` from 0 while `i < strs[0].size()`, check that every string has length > `i` and the same char at `i`.
3. On failure, return prefix `strs[0].substr(0, i)`.
4. If all columns match through `strs[0]`, return `strs[0]`.

## Complexity
- Time: O(n · m) where m is min string length
- Space: O(1) extra

## C++ Solution
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        for (int i = 0; i < static_cast<int>(strs[0].size()); ++i) {
            char c = strs[0][i];
            for (int j = 1; j < static_cast<int>(strs.size()); ++j) {
                if (i >= static_cast<int>(strs[j].size()) || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
```
