# LC 162. Find Peak Element

**Lists:** Top 150  
**Topic:** Binary Search  
**Difficulty:** Medium

## Problem
Find any peak index (`nums[i] > neighbors`). `nums[-1]` and `nums[n]` are −∞. O(log n).

## Intuition
If `nums[mid] < nums[mid+1]`, a peak exists on the right; else on the left (including mid).

## Approach
Binary search until `lo == hi`; that index is a peak.

## Complexity
- Time: O(log n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = (int)nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid + 1]) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
```
