# 253. Meeting Rooms II

**Lists:** Blind 75 (Premium), Top Interview 150  
**Topic:** Intervals (min heap)  
**Difficulty:** Medium  

## Problem

Given meeting intervals, return the minimum number of conference rooms required.

## Intuition

Sort by start. Min-heap of end times: if earliest ending meeting finishes before current starts, reuse room (pop); else need new room (push end).

## Approach

1. Sort by start.
2. `priority_queue` min-heap of end times (use `greater` on ints).
3. For each meeting, pop if `top <= start`, push `end`. Answer = max heap size.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> ends;
        ends.push(intervals[0][1]);
        for (int i = 1; i < (int)intervals.size(); ++i) {
            if (ends.top() <= intervals[i][0]) ends.pop();
            ends.push(intervals[i][1]);
        }
        return (int)ends.size();
    }
};
```
