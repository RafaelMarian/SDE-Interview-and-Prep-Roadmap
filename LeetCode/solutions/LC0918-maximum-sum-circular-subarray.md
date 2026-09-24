# LC 918. Maximum Sum Circular Subarray

**Lists:** Top 150
**Topic:** Arrays / Kadane
**Difficulty:** Medium

## Problem
Given a circular integer array `nums` (the end connects to the start), return the maximum sum of a non-empty subarray. Example: `nums = [5,-3,5]` → `10` (subarray `[5,5]` wrapping).

## Intuition
Either the best subarray does not wrap (standard Kadane), or it wraps around the circle — then it equals `totalSum - minimumSubarraySum`. Handle all-negative arrays separately.

## Approach
1. Track `curMax`, `bestMax`, `curMin`, `bestMin`, and `total` in one pass (Kadane variants).
2. If `bestMax < 0`, every element is negative; return `bestMax`.
3. Else return `max(bestMax, total - bestMin)`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int curMax = 0;
        int bestMax = INT_MIN;
        int curMin = 0;
        int bestMin = INT_MAX;
        for (int x : nums) {
            total += x;
            curMax = max(curMax + x, x);
            bestMax = max(bestMax, curMax);
            curMin = min(curMin + x, x);
            bestMin = min(bestMin, curMin);
        }
        if (bestMax < 0) {
            return bestMax;
        }
        return max(bestMax, total - bestMin);
    }
};
```
