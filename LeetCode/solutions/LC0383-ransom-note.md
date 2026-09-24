# LC 383. Ransom Note

**Lists:** Top 150
**Topic:** Hash Map
**Difficulty:** Easy

## Problem
Given strings `ransomNote` and `magazine`, return true if `ransomNote` can be constructed from letters in `magazine` (each letter used at most once).

## Intuition
Count available letters in `magazine`; decrement for each char needed in `ransomNote`. Fail if any count goes negative.

## Approach
1. Build frequency array of size 26 for `magazine`.
2. For each char in `ransomNote`, decrement count; if negative, return false.
3. Return true.

## Complexity
- Time: O(|ransomNote| + |magazine|)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> cnt{};
        for (char c : magazine) {
            ++cnt[c - 'a'];
        }
        for (char c : ransomNote) {
            if (--cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
```
