# 252. Meeting Rooms

**Lists:** Blind 75 (Premium)  
**Topic:** Intervals  
**Difficulty:** Easy  

## Problem

Given an array of meeting time intervals `[start, end]`, return `true` if a person can attend all meetings (no overlap).

## Intuition

Sort by start; any adjacent pair with `start[i] < end[i-1]` overlaps.

## Approach

1. Sort intervals by start.
2. Check consecutive pairs for overlap.

## Complexity

- **Time:** O(n log n)
- **Space:** O(1) extra

## C++ Solution

```cpp
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < (int)intervals.size(); ++i)
            if (intervals[i][0] < intervals[i - 1][1]) return false;
        return true;
    }
};
```
