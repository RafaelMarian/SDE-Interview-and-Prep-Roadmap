# 149. Max Points on a Line

**Lists:** Top Interview 150  
**Topic:** Math  
**Difficulty:** Hard  

## Problem

Given an array of `points` where `points[i] = [xi, yi]`, return the maximum number of points that lie on the same straight line.

## Intuition

Fix each point as anchor; count how many other points share the same reduced slope (dy, dx) with gcd normalization and a canonical sign. Track duplicate coincident points separately.

## Approach

1. For each anchor `i`, map `pair<int,int>` slope → count, plus `same` for points equal to anchor.
2. Slope from `(x1,y1)` to `(x2,y2)`: `dx = x2-x1`, `dy = y2-y1`; if both 0, increment `same`; else normalize with `gcd` and fix sign so dx ≥ 0 (or handle vertical).
3. Update global max with `same + max slope count`.

## Complexity

- **Time:** O(n²)
- **Space:** O(n) per anchor for the map

## C++ Solution

```cpp
class Solution {
    static pair<int, int> slopeKey(int dx, int dy) {
        if (dx == 0 && dy == 0) return {0, 0};
        int g = gcd(abs(dx), abs(dy));
        dx /= g;
        dy /= g;
        if (dx < 0) {
            dx = -dx;
            dy = -dy;
        }
        return {dx, dy};
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int best = 0;
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> cnt;
            int same = 1;
            int localMax = 0;
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0 && dy == 0) {
                    ++same;
                    continue;
                }
                auto key = slopeKey(dx, dy);
                int c = ++cnt[key];
                localMax = max(localMax, c);
            }
            best = max(best, same + localMax);
        }
        return best;
    }
};
```
