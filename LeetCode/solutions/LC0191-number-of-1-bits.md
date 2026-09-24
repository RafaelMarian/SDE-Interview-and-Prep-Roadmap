# 191. Number of 1 Bits

**Lists:** Blind 75, Top Interview 150  
**Topic:** Bit Manipulation  
**Difficulty:** Easy  

## Problem

Write a function that takes an unsigned integer and returns the number of `'1'` bits in its binary representation (Hamming weight).

## Intuition

Repeatedly clear lowest set bit with `n &= n - 1`; count iterations.

## Approach

While `n`, `n &= n - 1`, increment count.

## Complexity

- **Time:** O(number of 1 bits)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= n - 1;
            ++count;
        }
        return count;
    }
};
```
