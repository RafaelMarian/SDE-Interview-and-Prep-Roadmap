# 377. Combination Sum IV

**Lists:** Blind 75  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

Given distinct integers `nums` and target `target`, return the number of possible combinations that add up to `target`. Different sequences count as different combinations (order matters).

## Intuition

This is counting ordered sums: for each amount, sum ways from `amount - num` over all `nums`.

## Approach

1. `dp[0] = 1`.
2. For `a` from 1 to `target`, for each `num` in `nums`, if `num <= a`, `dp[a] += dp[a - num]`.
3. Return `dp[target]`.

## Complexity

- **Time:** O(target · |nums|)
- **Space:** O(target)

## C++ Solution

```cpp
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned> dp(target + 1, 0);
        dp[0] = 1;
        for (int a = 1; a <= target; ++a)
            for (int num : nums)
                if (num <= a) dp[a] += dp[a - num];
        return (int)dp[target];
    }
};
```
