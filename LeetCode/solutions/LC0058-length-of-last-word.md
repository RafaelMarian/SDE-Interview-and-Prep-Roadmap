# LC 58. Length of Last Word

**Lists:** Top 150
**Topic:** String
**Difficulty:** Easy

## Problem
Given a string `s` consisting of words and spaces, return the length of the last word. The last word is the maximum-length substring that is not a space.

## Intuition
Trim trailing spaces, then scan backward until the next space or start; count characters in that segment.

## Approach
1. Set `i = s.size() - 1`.
2. Skip trailing spaces while `i >= 0`.
3. Count length while characters are non-space.
4. Return the count.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = static_cast<int>(s.size()) - 1;
        while (i >= 0 && s[i] == ' ') {
            --i;
        }
        int len = 0;
        while (i >= 0 && s[i] != ' ') {
            ++len;
            --i;
        }
        return len;
    }
};
```
