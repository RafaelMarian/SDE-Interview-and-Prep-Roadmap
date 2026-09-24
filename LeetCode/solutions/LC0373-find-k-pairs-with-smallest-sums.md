# 373. Find K Pairs with Smallest Sums

**Lists:** Top Interview 150  
**Topic:** Heap  
**Difficulty:** Medium  

## Problem

You are given two integer arrays `nums1` and `nums2` sorted in non-decreasing order, and an integer `k`. Return the `k` pairs `(u, v)` with the smallest sums, where `u` is from `nums1` and `v` from `nums2`.

## Intuition

The smallest sum is `(nums1[0], nums2[0])`. From pair `(i, j)`, the next candidates are `(i+1, j)` and `(i, j+1)`. Use a min-heap and deduplicate states with a visited set.

## Approach

1. If either array is empty, return `{}`.
2. Push `(nums1[0] + nums2[0], 0, 0)` into a min-heap.
3. Pop `k` times: record `(nums1[i], nums2[j])`; if `i+1 < n1`, push `(i+1, j)` if unseen; if `j+1 < n2`, push `(i, j+1)` if unseen.
4. Use `set<pair<int,int>>` or similar to avoid duplicate indices in the heap.

## Complexity

- **Time:** O(k log k) heap operations (each push is O(log heap size))
- **Space:** O(k)

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k <= 0) return ans;

        using T = tuple<int, int, int>; // sum, i, j
        priority_queue<T, vector<T>, greater<T>> pq;
        set<pair<int, int>> seen;
        pq.emplace(nums1[0] + nums2[0], 0, 0);
        seen.emplace(0, 0);

        while (!pq.empty() && (int)ans.size() < k) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (i + 1 < (int)nums1.size() && !seen.count({i + 1, j})) {
                seen.emplace(i + 1, j);
                pq.emplace(nums1[i + 1] + nums2[j], i + 1, j);
            }
            if (j + 1 < (int)nums2.size() && !seen.count({i, j + 1})) {
                seen.emplace(i, j + 1);
                pq.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }
        return ans;
    }
};
```
