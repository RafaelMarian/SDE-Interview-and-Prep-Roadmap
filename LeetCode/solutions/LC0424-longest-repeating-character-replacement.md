# LC 424. Longest Repeating Character Replacement

**Lists:** Blind 75 · Top 150
**Topic:** Sliding Window
**Difficulty:** Medium

## Problem
Given a string `s` and integer `k`, you may change at most `k` characters so the resulting string has the same letter repeated. Return the maximum length of such a substring. Example: `s = "ABAB", k = 2` → `4` (change both `A`s or both `B`s).

## Intuition
In a valid window of length `L`, the most frequent character count `maxFreq` satisfies `L - maxFreq <= k` (at most `k` replacements). Expand the window while valid; when invalid, shrink from the left.

## Approach
1. Track frequency of each uppercase letter in the window and `maxFreq`.
2. Expand `right`, update counts and `maxFreq`.
3. While `windowSize - maxFreq > k`, decrement count at `left` and shrink.
4. Track maximum window size.

## Complexity
- Time: O(n)
- Space: O(1) — 26 letters

## C++ Solution
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 26> count{};
        int left = 0;
        int maxFreq = 0;
        int best = 0;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            ++count[s[right] - 'A'];
            maxFreq = max(maxFreq, count[s[right] - 'A']);
            while (right - left + 1 - maxFreq > k) {
                --count[s[left] - 'A'];
                ++left;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
```
