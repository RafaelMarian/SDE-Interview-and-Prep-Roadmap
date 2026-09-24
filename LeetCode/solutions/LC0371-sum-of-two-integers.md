# 371. Sum of Two Integers

**Lists:** Blind 75, Top Interview 150  
**Topic:** Bit Manipulation  
**Difficulty:** Medium  

## Problem

Given two integers `a` and `b`, return the sum without using `+` or `-` operators.

## Intuition

Binary addition: sum without carry is `a ^ b`; carry is `(a & b) << 1`. Repeat until carry is 0.

## Approach

While `b != 0`, compute `carry = (a & b) << 1`, `a = a ^ b`, `b = carry`. Mask to 32 bits if needed for LeetCode signed overflow rules (often unnecessary in C++ for this problem).

## Complexity

- **Time:** O(1) bit width
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (unsigned)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
```
