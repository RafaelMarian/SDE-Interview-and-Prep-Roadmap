# LC 27. Remove Element

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Easy

## Problem
Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in-place. Return the number of elements not equal to `val`. The order of remaining elements may change.

## Intuition
Maintain a write index for the next kept element. Scan the array; whenever the current value is not `val`, copy it forward.

## Approach
1. Initialize `k = 0`.
2. For each `nums[i]`, if `nums[i] != val`, set `nums[k++] = nums[i]`.
3. Return `k`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int x : nums) {
            if (x != val) {
                nums[k++] = x;
            }
        }
        return k;
    }
};
```
