# LC 209. Minimum Size Subarray Sum

**Lists:** Top 150
**Topic:** Sliding Window
**Difficulty:** Medium

## Problem
Given an array of positive integers `nums` and positive integer `target`, return the minimal length of a contiguous subarray whose sum is ≥ `target`. Return 0 if none exists.

## Intuition
Expand the window with a right pointer, adding to sum; when sum ≥ target, shrink from the left while recording minimum length.

## Approach
1. Set `l = 0`, `sum = 0`, `ans = INT_MAX`.
2. For `r` from 0 to `n - 1`, add `nums[r]`.
3. While `sum >= target`, update `ans`, subtract `nums[l++]`.
4. Return 0 if `ans` unchanged, else `ans`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, sum = 0, ans = INT_MAX;
        for (int r = 0; r < static_cast<int>(nums.size()); ++r) {
            sum += nums[r];
            while (sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```
