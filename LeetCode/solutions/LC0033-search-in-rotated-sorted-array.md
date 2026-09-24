# LC 33. Search in Rotated Sorted Array

**Lists:** Blind 75 · Top 150
**Topic:** Binary Search
**Difficulty:** Medium

## Problem
Given a rotated sorted array `nums` (distinct) and `target`, return the index of `target` or `-1` if absent. Example: `nums = [4,5,6,7,0,1,2], target = 0` → `4`.

## Intuition
At each `mid`, one side `[left, mid]` or `[mid, right]` is still sorted. Check which half is ordered, then test whether `target` lies in that sorted range to decide which half to search.

## Approach
1. Binary search with `left`, `right`.
2. If `nums[mid] == target`, return `mid`.
3. If left half is sorted (`nums[left] <= nums[mid]`): if `target` in `[nums[left], nums[mid])`, search left; else right.
4. Else right half is sorted: if `target` in `(nums[mid], nums[right]]`, search right; else left.
5. Return `-1` if loop ends.

## Complexity
- Time: O(log n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
```
