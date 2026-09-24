# LC 162. Find Peak Element

**Lists:** Top 150
**Topic:** Binary Search
**Difficulty:** Medium

## Problem
A peak element is strictly greater than its neighbors. Given a 0-indexed integer array `nums`, find a peak element and return its index. If multiple peaks, return any. Assume `nums[-1] = nums[n] = -∞`. Must be O(log n). Example: `nums = [1,2,3,1]` → `2` (peak value 3).

## Intuition
If `nums[mid] < nums[mid+1]`, a peak exists to the right (ascending slope). Otherwise a peak is at `mid` or to the left.

## Approach
1. Binary search with `lo = 0`, `hi = n - 1`.
2. While `lo < hi`, compare `nums[mid]` and `nums[mid + 1]`.
3. If ascending at `mid`, set `lo = mid + 1`; else `hi = mid`.
4. Return `lo`.

## Complexity
- Time: O(log n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0;
        int hi = static_cast<int>(nums.size()) - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid + 1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
```
