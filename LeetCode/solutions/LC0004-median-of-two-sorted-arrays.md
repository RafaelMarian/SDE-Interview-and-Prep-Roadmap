# LC 4. Median of Two Sorted Arrays
**Lists:** Top 150  
**Topic:** Binary Search  
**Difficulty:** Hard

## Problem (short + example)

Two sorted arrays; return the median of the merged order in O(log(m+n)) time.

**Example:** `nums1=[1,3]`, `nums2=[2]` → 2.0.

## Intuition

Binary search the partition in the shorter array: choose `i` elements from A and `j` from B so left half has `k = (m+n+1)/2` elements and max(left) ≤ min(right).

## Approach

1. Ensure `A` is shorter; binary search `i` in `[0,m]`, `j = k - i`.
2. Check valid partition with left max ≤ right min (handle empty sides with ±∞).
3. If valid, median from left/right max depending on odd/even length; else move `i`.

## Complexity

- **Time:** O(log(min(m,n)))  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = (int)nums1.size(), n = (int)nums2.size();
        int lo = 0, hi = m;
        int total = m + n;
        int leftCount = (total + 1) / 2;
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2;
            int j = leftCount - i;
            int aLeft = i > 0 ? nums1[i - 1] : INT_MIN;
            int aRight = i < m ? nums1[i] : INT_MAX;
            int bLeft = j > 0 ? nums2[j - 1] : INT_MIN;
            int bRight = j < n ? nums2[j] : INT_MAX;
            if (aLeft <= bRight && bLeft <= aRight) {
                if (total % 2) return max(aLeft, bLeft);
                return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
            }
            if (aLeft > bRight) hi = i - 1;
            else lo = i + 1;
        }
        return 0.0;
    }
};
```
