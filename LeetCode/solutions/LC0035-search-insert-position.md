# LC 35. Search Insert Position
**Lists:** Top 150  
**Topic:** Binary Search  
**Difficulty:** Easy

## Problem (short + example)

Sorted array and `target`: return index if found, else index where it would be inserted.

**Example:** `nums=[1,3,5,6]`, `target=5` → 2; `target=2` → 1.

## Intuition

Lower bound binary search: first index with `nums[i] >= target`.

## Approach

1. `lo=0`, `hi=n`.
2. While `lo < hi`, `mid = lo + (hi-lo)/2`; if `nums[mid] < target`, `lo = mid+1`; else `hi = mid`.
3. Return `lo`.

## Complexity

- **Time:** O(log n)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = (int)nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
```
