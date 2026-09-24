# 268. Missing Number

**Lists:** Blind 75, Top Interview 150  
**Topic:** Bit Manipulation / Math  
**Difficulty:** Easy  

## Problem

Given an array `nums` containing `n` distinct numbers in `[0, n]`, return the one number missing from the array.

## Intuition

XOR all indices `0..n` with all values in `nums`; pairs cancel, missing remains.

## Approach

`xor` from `i = 0` to `n` with `nums[i]` when `i < n`.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 0; i <= n; ++i) {
            x ^= i;
            if (i < n) x ^= nums[i];
        }
        return x;
    }
};
```
