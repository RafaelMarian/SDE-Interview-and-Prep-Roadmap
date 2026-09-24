# LC 26. Remove Duplicates from Sorted Array

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Easy

## Problem
Given a sorted array `nums`, remove duplicates in-place so each element appears at most once. Return the number of unique elements `k`; the first `k` slots of `nums` must hold those unique values in order.

## Intuition
Because the array is sorted, duplicates are adjacent. Keep a slow pointer for the last unique position; advance the fast pointer and copy when you see a new value.

## Approach
1. If empty, return 0.
2. Set `k = 1`.
3. For `i` from 1 to end, if `nums[i] != nums[k - 1]`, set `nums[k++] = nums[i]`.
4. Return `k`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int k = 1;
        for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] != nums[k - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
```
