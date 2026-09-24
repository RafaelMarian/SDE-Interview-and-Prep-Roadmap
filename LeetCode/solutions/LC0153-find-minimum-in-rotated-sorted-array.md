# LC 153. Find Minimum in Rotated Sorted Array

**Lists:** Blind 75 · Top 150
**Topic:** Binary Search
**Difficulty:** Medium

## Problem
Given a sorted array rotated between `1` and `n` times (all distinct), return the minimum element. Example: `nums = [3,4,5,1,2]` → `1`.

## Intuition
In a rotated array, the minimum is the pivot where `nums[mid] > nums[right]`. If the right half is not sorted (`nums[mid] > nums[right]`), the min lies to the right of `mid`; otherwise it is at `mid` or to the left.

## Approach
1. Set `left = 0`, `right = n - 1`.
2. While `left < right`, `mid = left + (right - left) / 2`.
3. If `nums[mid] > nums[right]`, `left = mid + 1`; else `right = mid`.
4. Return `nums[left]`.

## Complexity
- Time: O(log n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
```
