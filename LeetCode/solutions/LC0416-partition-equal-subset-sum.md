# 416. Partition Equal Subset Sum

**Lists:** Blind 75, Top Interview 150  
**Topic:** 1D DP (subset sum)  
**Difficulty:** Medium  

## Problem

Given a non-empty array `nums` of positive integers, return `true` if you can partition into two subsets with equal sum.

## Intuition

Target half-sum `S/2`. Classic subset-sum DP: `dp[s]` achievable?

## Approach

1. Sum nums; if odd, false.
2. `target = sum/2`, `dp[0]=true`.
3. For each `num`, for `s` from `target` down to `num`, `dp[s] |= dp[s-num]`.

## Complexity

- **Time:** O(n · target)
- **Space:** O(target)

## C++ Solution

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums)
            for (int s = target; s >= num; --s)
                dp[s] = dp[s] || dp[s - num];
        return dp[target];
    }
};
```
