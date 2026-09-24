# LC 242. Valid Anagram

**Lists:** Blind 75 · Top 150
**Topic:** Arrays & Hashing
**Difficulty:** Easy

## Problem
Given two strings `s` and `t`, return `true` if `t` is an anagram of `s` (same letters, same counts). Example: `s = "anagram", t = "nagaram"` → `true`.

## Intuition
Anagrams have identical character frequency. Count letters in `s`, decrement while scanning `t`; any mismatch or leftover count means not an anagram.

## Approach
1. If lengths differ, return `false`.
2. Use a frequency array of size 26 for lowercase letters.
3. Increment counts for characters in `s`.
4. Decrement counts for characters in `t`; if any count goes negative, return `false`.
5. Return `true` if all counts are zero (implicitly satisfied if no negative and lengths match).

## Complexity
- Time: O(n)
- Space: O(1) — fixed alphabet size

## C++ Solution
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        array<int, 26> count{};
        for (char c : s) {
            ++count[c - 'a'];
        }
        for (char c : t) {
            if (--count[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
```
