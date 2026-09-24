# 9. Palindrome Number

**Lists:** Top Interview 150  
**Topic:** Math  
**Difficulty:** Easy  

## Problem

Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise. Follow up: could you solve it without converting the integer to a string?

## Intuition

Compare digits from both ends by reversing half the number: when the reversed half meets or passes the remaining front half, check equality (even length) or front equals reversed/10 (odd length).

## Approach

1. Negative numbers and numbers ending in 0 (except 0) are not palindromes.
2. While `x > reversed && x > 0`, peel last digit: `reversed = reversed * 10 + x % 10`, `x /= 10`.
3. Return `x == reversed || x == reversed / 10`.

## Complexity

- **Time:** O(log₁₀ x)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return x == reversed || x == reversed / 10;
    }
};
```
