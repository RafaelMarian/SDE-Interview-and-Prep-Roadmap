# LC 11. Container With Most Water

**Lists:** Blind 75 · Top 150
**Topic:** Two Pointers
**Difficulty:** Medium

## Problem
Given `n` non-negative integers `height` where each line is `height[i]`, find two lines that together with the x-axis form a container that holds the most water. Return the maximum amount. Example: `height = [1,8,6,2,5,4,8,3,7]` → `49`.

## Intuition
Area with pointers `left` and `right` is `min(height[left], height[right]) * (right - left)`. Move the pointer at the shorter line inward; keeping the shorter side cannot increase area because width only shrinks.

## Approach
1. Initialize `left = 0`, `right = n - 1`, `best = 0`.
2. While `left < right`, compute area and update `best`.
3. If `height[left] < height[right]`, increment `left`; else decrement `right`.
4. Return `best`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int best = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            best = max(best, h * (right - left));
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return best;
    }
};
```
