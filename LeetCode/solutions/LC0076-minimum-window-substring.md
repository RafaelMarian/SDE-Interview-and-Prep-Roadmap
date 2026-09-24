# LC 76. Minimum Window Substring

**Lists:** Blind 75 · Top 150
**Topic:** Sliding Window
**Difficulty:** Hard

## Problem
Given strings `s` and `t`, return the minimum window substring of `s` such that every character in `t` (including multiplicity) is included. If none exists, return `""`. Example: `s = "ADOBECODEBANC", t = "ABC"` → `"BANC"`.

## Intuition
Expand the right edge until the window contains all required characters, then contract from the left to minimize length while still valid. Track how many of each required character are still needed with a frequency map.

## Approach
1. Build `need` counts for characters in `t`; `missing` = total required count.
2. Expand `right`: if `s[right]` is needed, decrement `missing`.
3. When `missing == 0`, update best window and shrink `left` while restoring validity.
4. Return substring from best `(start, length)`.

## Complexity
- Time: O(|s| + |t|)
- Space: O(|t|) for frequency map

## C++ Solution
```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        for (char c : t) {
            ++need[c];
        }
        int missing = static_cast<int>(t.size());
        int left = 0;
        int start = 0;
        int len = INT_MAX;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            char c = s[right];
            if (need.count(c)) {
                if (need[c] > 0) {
                    --missing;
                }
                --need[c];
            }
            while (missing == 0) {
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    start = left;
                }
                char leftChar = s[left];
                if (need.count(leftChar)) {
                    ++need[leftChar];
                    if (need[leftChar] > 0) {
                        ++missing;
                    }
                }
                ++left;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
```
