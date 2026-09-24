# 152. Maximum Product Subarray

**Lists:** Blind 75, Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

Given an integer array `nums`, find a contiguous subarray with the largest product and return that product.

## Intuition

Track max and min product ending here (min catches negative × negative). Update with `x`, `maxPrev * x`, `minPrev * x`.

## Approach

Initialize `maxP = minP = result = nums[0]`. For each next `x`, compute new max/min, update global result.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = nums[0], minP = nums[0], ans = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            int x = nums[i];
            if (x < 0) swap(maxP, minP);
            maxP = max(x, maxP * x);
            minP = min(x, minP * x);
            ans = max(ans, maxP);
        }
        return ans;
    }
};
```
