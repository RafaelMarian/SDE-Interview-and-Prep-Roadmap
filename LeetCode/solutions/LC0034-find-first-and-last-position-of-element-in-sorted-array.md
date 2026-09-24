# LC 34. Find First and Last Position of Element in Sorted Array
**Lists:** Top 150  
**Topic:** Binary Search  
**Difficulty:** Medium

## Problem (short + example)

Sorted array with duplicates: return start and end indices of `target`, or `[-1,-1]`.

**Example:** `nums=[5,7,7,8,8,10]`, `target=8` → `[3,4]`.

## Intuition

Two binary searches: lower bound for first, upper bound (first > target) minus one for last.

## Approach

1. `lowerBound`: first `i` with `nums[i] >= target`.
2. If out of range or `nums[lo] != target`, return `{-1,-1}`.
3. `upperBound`: first `i` with `nums[i] > target`; answer `{lo, hi-1}`.

## Complexity

- **Time:** O(log n)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
    int bound(vector<int>& nums, int target, bool upper) {
        int lo = 0, hi = (int)nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target || (upper && nums[mid] == target)) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = bound(nums, target, false);
        if (first == (int)nums.size() || nums[first] != target) return {-1, -1};
        int last = bound(nums, target, true) - 1;
        return {first, last};
    }
};
```
