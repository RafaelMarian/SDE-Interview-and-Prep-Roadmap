# LC 452. Minimum Number of Arrows to Burst Balloons

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Medium

## Problem
Balloons are intervals `[xstart, xend]`. An arrow shot at `x` bursts any balloon with `xstart <= x <= xend`. Return the minimum arrows to burst all balloons.

## Intuition
Sort by end coordinate. Greedily place an arrow at the end of the first balloon; skip balloons already burst; when one is not burst, place a new arrow at its end.

## Approach
1. Sort balloons by increasing `end`.
2. Track `arrows = 0`, `lastEnd = LLONG_MIN`.
3. For each balloon, if `start > lastEnd`, increment arrows and set `lastEnd = end`.
4. Return `arrows`.

## Complexity
- Time: O(n log n)
- Space: O(1) extra excluding sort

## C++ Solution
```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        long long lastEnd = LLONG_MIN;
        int arrows = 0;
        for (const auto& p : points) {
            if (static_cast<long long>(p[0]) > lastEnd) {
                ++arrows;
                lastEnd = p[1];
            }
        }
        return arrows;
    }
};
```
