# 53. Maximum Subarray

**Lists:** Blind 75, Top Interview 150  
**Topic:** 1D DP / Kadane  
**Difficulty:** Medium  

## Problem

Find the contiguous subarray with the largest sum and return that sum.

## Intuition

Kadane: either extend current subarray or start fresh at `nums[i]`.

## Approach

`cur = max(nums[i], cur + nums[i])`, `best = max(best, cur)`.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0], best = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            cur = max(nums[i], cur + nums[i]);
            best = max(best, cur);
        }
        return best;
    }
};
```
