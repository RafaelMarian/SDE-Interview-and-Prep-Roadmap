# 435. Non-overlapping Intervals

**Lists:** Blind 75, Top Interview 150  
**Topic:** Intervals (greedy)  
**Difficulty:** Medium  

## Problem

Given intervals, return the minimum number of intervals to remove so the rest are non-overlapping.

## Intuition

Equivalent to max number of non-overlapping intervals. Greedy: sort by end time, take interval if start ≥ last end.

## Approach

1. Sort by `end`.
2. Count kept intervals with greedy end pointer.
3. Answer = `n - kept`.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1) extra

## C++ Solution

```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int kept = 1, end = intervals[0][1];
        for (int i = 1; i < (int)intervals.size(); ++i) {
            if (intervals[i][0] >= end) {
                ++kept;
                end = intervals[i][1];
            }
        }
        return (int)intervals.size() - kept;
    }
};
```
