# 57. Insert Interval

**Lists:** Blind 75, Top Interview 150  
**Topic:** Intervals  
**Difficulty:** Medium  

## Problem

Given sorted non-overlapping intervals and a new interval, insert and merge if necessary.

## Intuition

Three phases: take intervals ending before new starts, merge overlapping with new, append the rest.

## Approach

1. Push intervals with `end < newInterval.start`.
2. While intervals overlap new (`start <= newInterval.end`), merge into `newInterval`.
3. Push `newInterval`, then remaining intervals.

## Complexity

- **Time:** O(n)
- **Space:** O(n) output

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0])
            result.push_back(intervals[i++]);
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        result.push_back(newInterval);
        while (i < n) result.push_back(intervals[i++]);
        return result;
    }
};
```
