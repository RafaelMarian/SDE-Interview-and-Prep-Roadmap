# LC 392. Is Subsequence

**Lists:** Top 150
**Topic:** Two Pointers
**Difficulty:** Easy

## Problem
Given strings `s` and `t`, return true if `s` is a subsequence of `t` (you can delete some characters of `t` without changing order to get `s`).

## Intuition
Scan `t` with a pointer into `s`; whenever characters match, advance in `s`. Success if all of `s` is matched.

## Approach
1. Set `i = 0`.
2. For each char `c` in `t`, if `i < s.size()` and `s[i] == c`, increment `i`.
3. Return `i == s.size()`.

## Complexity
- Time: O(|t|)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (char c : t) {
            if (i < static_cast<int>(s.size()) && s[i] == c) {
                ++i;
            }
        }
        return i == static_cast<int>(s.size());
    }
};
```
