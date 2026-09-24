# 56. Merge Intervals

**Lists:** Blind 75, Top Interview 150  
**Topic:** Intervals  
**Difficulty:** Medium  

## Problem

Given an array of intervals, merge all overlapping intervals and return the result.

## Intuition

Sort by start; extend current interval if next starts before or at current end, else push and start new.

## Approach

1. Sort intervals by `start`.
2. Initialize `merged` with first interval.
3. For each next, if overlaps last in `merged`, extend end; else append.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n) output

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for (int i = 1; i < (int)intervals.size(); ++i) {
            if (intervals[i][0] <= merged.back()[1])
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            else
                merged.push_back(intervals[i]);
        }
        return merged;
    }
};
```
