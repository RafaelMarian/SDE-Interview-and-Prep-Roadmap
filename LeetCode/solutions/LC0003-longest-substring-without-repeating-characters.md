# LC 3. Longest Substring Without Repeating Characters

**Lists:** Blind 75 · Top 150
**Topic:** Sliding Window
**Difficulty:** Medium

## Problem
Given a string `s`, find the length of the longest substring without repeating characters. Example: `s = "abcabcbb"` → `3` (`"abc"`).

## Intuition
Maintain a window `[left, right]` with all distinct characters. When `s[right]` repeats, shrink from the left until the duplicate is removed. Track the maximum window size.

## Approach
1. Use `unordered_map<char,int>` storing last index of each character.
2. Expand `right`, updating answer with `right - left + 1`.
3. If `s[right]` was seen at index `>= left`, move `left` to `last + 1`.
4. Store `s[right]`'s index and continue.

## Complexity
- Time: O(n)
- Space: O(min(n, alphabet size))

## C++ Solution
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last;
        int left = 0;
        int best = 0;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            char c = s[right];
            if (last.count(c) && last[c] >= left) {
                left = last[c] + 1;
            }
            last[c] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
```
