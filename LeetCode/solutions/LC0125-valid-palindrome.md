# LC 125. Valid Palindrome

**Lists:** Blind 75 · Top 150
**Topic:** Two Pointers
**Difficulty:** Easy

## Problem
Given a string `s`, return `true` if it is a palindrome after converting all uppercase letters to lowercase and removing non-alphanumeric characters. Example: `s = "A man, a plan, a canal: Panama"` → `true`.

## Intuition
Compare characters from both ends inward, skipping invalid symbols. Only alphanumeric characters matter, compared case-insensitively.

## Approach
1. Set `left = 0`, `right = s.size() - 1`.
2. While `left < right`, advance `left` or retreat `right` past non-alphanumeric chars.
3. If `tolower(s[left]) != tolower(s[right])`, return `false`.
4. Move both pointers inward.
5. Return `true` when pointers meet.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        auto isAlnum = [](char c) {
            return isalnum(static_cast<unsigned char>(c));
        };
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;
        while (left < right) {
            while (left < right && !isAlnum(s[left])) {
                ++left;
            }
            while (left < right && !isAlnum(s[right])) {
                --right;
            }
            if (tolower(static_cast<unsigned char>(s[left])) !=
                tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
```
