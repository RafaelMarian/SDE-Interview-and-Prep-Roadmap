# LC 918. Maximum Sum Circular Subarray

**Lists:** Top 150  
**Topic:** Kadane  
**Difficulty:** Medium

## Problem
Max subarray sum on a circular array (wrap-around allowed).

## Intuition
Case A: normal Kadane max. Case B: wrap = `total - minSubarray`. Answer = max(A, B) unless all negative (then just max element / Kadane max).

## Approach
1. Compute `maxKadane`, `minKadane`, `total`.  
2. If `maxKadane < 0` return it.  
3. Else return `max(maxKadane, total - minKadane)`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;
        for (int x : nums) {
            curMax = max(x, curMax + x);
            maxSum = max(maxSum, curMax);
            curMin = min(x, curMin + x);
            minSum = min(minSum, curMin);
            total += x;
        }
        if (maxSum < 0) return maxSum;
        return max(maxSum, total - minSum);
    }
};
```
