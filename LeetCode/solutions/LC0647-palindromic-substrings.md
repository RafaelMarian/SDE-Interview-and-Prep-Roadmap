# 647. Palindromic Substrings

**Lists:** Blind 75, Top Interview 150  
**Topic:** 1D DP / Expand Around Center  
**Difficulty:** Medium  

## Problem

Given a string `s`, return the number of palindromic substrings in `s`.

## Intuition

Every palindrome expands from a center (one or two chars). Count palindromes while expanding from each center.

## Approach

For each index `i`, expand odd (`i,i`) and even (`i,i+1`) centers while chars match, increment count each step.

## Complexity

- **Time:** O(n²)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
    int expand(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            ++count;
            --left;
            ++right;
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            ans += expand(s, i, i);
            ans += expand(s, i, i + 1);
        }
        return ans;
    }
};
```
