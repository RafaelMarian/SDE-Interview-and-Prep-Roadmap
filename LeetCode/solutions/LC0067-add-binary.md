# 67. Add Binary

**Lists:** Top Interview 150  
**Topic:** Bit Manipulation  
**Difficulty:** Easy  

## Problem

Given two binary strings `a` and `b`, return their sum as a binary string.

## Intuition

Add from least significant bit with carry, same as decimal addition. Process both strings from the end; append `'0'` or `'1'` and reverse at the end.

## Approach

1. Pointers `i`, `j` at ends of `a` and `b`, carry `c` initially 0.
2. While `i >= 0`, `j >= 0`, or `c`: sum bits from each string (if in range) plus carry; append `sum % 2`; carry = `sum / 2`; move pointers left.
3. Reverse the built string.

## Complexity

- **Time:** O(max(|a|, |b|))
- **Space:** O(max(|a|, |b|)) for output

## C++ Solution

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = (int)a.size() - 1, j = (int)b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res.push_back(char('0' + (sum & 1)));
            carry = sum >> 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
