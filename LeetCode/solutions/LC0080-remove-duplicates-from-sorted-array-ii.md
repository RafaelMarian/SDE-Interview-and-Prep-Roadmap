# LC 80. Remove Duplicates from Sorted Array II

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Medium

## Problem
Given a sorted array `nums`, remove duplicates in-place so each element appears at most twice. Return the count `k` of elements in the result; the first `k` entries of `nums` must hold the result in order.

## Intuition
Generalize the two-pointer idea: allow at most two copies of each value. A new value can be appended if it differs from the element two positions back in the write region.

## Approach
1. If `size <= 2`, return size.
2. Set `k = 2` (first two elements always stay).
3. For `i` from 2 onward, if `nums[i] != nums[k - 2]`, append `nums[i]` at `k++`.
4. Return `k`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 2) {
            return n;
        }
        int k = 2;
        for (int i = 2; i < n; ++i) {
            if (nums[i] != nums[k - 2]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
```
