# 172. Factorial Trailing Zeroes

**Lists:** Top Interview 150  
**Topic:** Math  
**Difficulty:** Medium  

## Problem

Given an integer `n`, return the number of trailing zeroes in `n!`.

## Intuition

Trailing zeros come from factors of 10 = 2 × 5. There are always more factors of 2 than 5, so count how many times 5 divides into the product 1 × 2 × … × n.

## Approach

1. Add `n/5 + n/25 + n/125 + …` while divisor ≤ n.
2. Each term counts multiples of that power of 5.

## Complexity

- **Time:** O(log₅ n)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for (long long p = 5; p <= n; p *= 5) count += n / p;
        return count;
    }
};
```
