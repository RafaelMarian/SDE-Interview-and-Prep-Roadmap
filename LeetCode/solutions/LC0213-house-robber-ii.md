# 213. House Robber II

**Lists:** Blind 75, Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

Houses are arranged in a circle: the first and last house are neighbors. Maximize robbery total without robbing adjacent houses.

## Intuition

Either rob houses `0 .. n-2` or `1 .. n-1`, never both endpoints. Run linear house robber on both ranges and take the max.

## Approach

1. If `n == 1`, return `nums[0]`.
2. `robRange(0, n-2)` and `robRange(1, n-1)`.
3. Helper same as House Robber I on `[start, end]`.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
    int robLinear(const vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; ++i) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
};
```
