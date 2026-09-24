# 215. Kth Largest Element in an Array

**Lists:** Top Interview 150  
**Topic:** Heap  
**Difficulty:** Medium  

## Problem

Given an integer array `nums` and an integer `k`, return the `k`th largest element in the array. Note that it is the `k`th largest in sorted order, not the `k`th distinct element.

## Intuition

Maintain a min-heap of size `k`: the root is always the weakest among the top `k` candidates seen so far. Anything smaller than the root cannot be in the top `k`. Quickselect is also valid; the heap approach is straightforward and works well when `k` is modest.

## Approach

1. Use a min-heap (priority queue with `greater<int>`) capped at size `k`.
2. For each `x` in `nums`: push `x`; if size exceeds `k`, pop the smallest.
3. Return the heap top after one pass.

## Complexity

- **Time:** O(n log k)
- **Space:** O(k)

## C++ Solution

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int x : nums) {
            minHeap.push(x);
            if ((int)minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};
```
