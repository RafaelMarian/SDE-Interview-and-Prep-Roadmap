# 198. House Robber

**Lists:** Blind 75, Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

Given non-negative integers representing money in each house, rob non-adjacent houses to maximize total. Cannot rob two adjacent houses.

## Intuition

At house `i`, either skip it (keep best up to `i-1`) or rob it (best up to `i-2` + `nums[i]`).

## Approach

`prev2` = best excluding previous house, `prev1` = best including up to previous. Update each house.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;
        for (int x : nums) {
            int cur = max(prev1, prev2 + x);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
```
