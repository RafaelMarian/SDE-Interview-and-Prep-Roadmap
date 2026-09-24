# LC 88. Merge Sorted Array

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Easy

## Problem
You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and integers `m` and `n` representing the number of elements in `nums1` and `nums2`. Merge `nums2` into `nums1` as one sorted array in-place. The first `m` elements of `nums1` are valid; the rest is buffer space of size `n`.

## Intuition
Merging from the front would shift elements in `nums1`. Fill from the back: compare the largest remaining values from both arrays and place the larger at the end of the merged region.

## Approach
1. Set three pointers: `i = m - 1`, `j = n - 1`, `k = m + n - 1`.
2. While both arrays have elements, place the larger of `nums1[i]` and `nums2[j]` at `nums1[k--]`.
3. Copy any remaining elements from `nums2` (remaining `nums1` elements are already in place).

## Complexity
- Time: O(m + n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};
```
