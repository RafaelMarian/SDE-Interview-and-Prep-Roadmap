# LC 28. Find the Index of the First Occurrence in a String

**Lists:** Top 150
**Topic:** String
**Difficulty:** Easy

## Problem
Given strings `haystack` and `needle`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

## Intuition
Naive sliding window: for each start index where the window fits, compare substring to `needle`.

## Approach
1. Let `n = haystack.size()`, `m = needle.size()`.
2. If `m == 0`, return 0.
3. For `i` from 0 to `n - m`, if `haystack.compare(i, m, needle) == 0`, return `i`.
4. Return `-1`.

## Complexity
- Time: O(n · m) worst case
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = static_cast<int>(haystack.size());
        int m = static_cast<int>(needle.size());
        if (m == 0) {
            return 0;
        }
        for (int i = 0; i <= n - m; ++i) {
            if (haystack.compare(i, m, needle) == 0) {
                return i;
            }
        }
        return -1;
    }
};
```
