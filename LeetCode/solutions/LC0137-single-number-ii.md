# 137. Single Number II

**Lists:** Top Interview 150  
**Topic:** Bit Manipulation  
**Difficulty:** Medium  

## Problem

Given an integer array `nums` where every element appears three times except for one, which appears exactly once, find the single element and implement it in linear time using constant extra space.

## Intuition

Track counts mod 3 per bit without storing full counts for every number. Two registers `ones` and `twos` encode how many times each bit has been seen modulo 3.

## Approach

1. For each `x`, update: `ones = (ones ^ x) & ~twos`, `twos = (twos ^ x) & ~ones`.
2. After processing, `ones` holds the unique number.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int x : nums) {
            ones = (ones ^ x) & ~twos;
            twos = (twos ^ x) & ~ones;
        }
        return ones;
    }
};
```
