# LC 42. Trapping Rain Water

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Hard

## Problem
Given non-negative integer bar heights `height`, compute how much water can be trapped after raining.

## Intuition
Water at index `i` is bounded by the max height to its left and right: `min(leftMax, rightMax) - height[i]`. Two pointers track left/right max while moving the shorter side inward.

## Approach
1. Pointers `l = 0`, `r = n - 1`, `leftMax = 0`, `rightMax = 0`, `water = 0`.
2. While `l < r`, update max on the shorter side and add trapped water at that side, then move the pointer.
3. Return `water`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = static_cast<int>(height.size()) - 1;
        int leftMax = 0, rightMax = 0, water = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                leftMax = max(leftMax, height[l]);
                water += leftMax - height[l];
                ++l;
            } else {
                rightMax = max(rightMax, height[r]);
                water += rightMax - height[r];
                --r;
            }
        }
        return water;
    }
};
```
