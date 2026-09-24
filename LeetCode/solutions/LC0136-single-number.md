# 136. Single Number

**Lists:** Top Interview 150  
**Topic:** Bit Manipulation  
**Difficulty:** Easy  

## Problem

Given a non-empty array of integers `nums`, every element appears twice except for one. Find that single one. You must implement a solution with linear runtime and use only constant extra space.

## Intuition

XOR cancels pairs: `a ^ a = 0` and `x ^ 0 = x`. XOR all numbers; duplicates vanish, leaving the lone value.

## Approach

1. Initialize `ans = 0`.
2. XOR every element into `ans`.
3. Return `ans`.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};
```
