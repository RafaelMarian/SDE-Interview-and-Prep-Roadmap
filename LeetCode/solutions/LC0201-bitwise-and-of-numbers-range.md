# 201. Bitwise AND of Numbers Range

**Lists:** Top Interview 150  
**Topic:** Bit Manipulation  
**Difficulty:** Medium  

## Problem

Given two integers `left` and `right`, return the bitwise AND of all numbers in the inclusive range `[left, right]`.

## Intuition

Once a bit flips from 1 to 0 somewhere in the range, that bit is 0 in the final AND. The result equals the common prefix of `left` and `right` in binary (shift both right until equal, then shift back).

## Approach

1. While `left < right`, shift both `left` and `right` right by 1 (drop differing low bits).
2. Shift `left` left by the number of shifts performed (or multiply by 2^shiftCount).
3. Return `left`.

## Complexity

- **Time:** O(log max(left, right))
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }
        return left << shift;
    }
};
```
