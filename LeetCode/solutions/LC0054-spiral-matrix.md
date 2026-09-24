# 54. Spiral Matrix

**Lists:** Blind 75, Top Interview 150  
**Topic:** Matrix  
**Difficulty:** Medium  

## Problem

Given an `m x n` matrix, return all elements in spiral order.

## Intuition

Maintain four boundaries `top, bottom, left, right`; peel one layer at a time.

## Approach

While `top <= bottom && left <= right`, traverse right along top, down right col, left on bottom (if distinct row), up left col (if distinct col), shrink bounds.

## Complexity

- **Time:** O(m · n)
- **Space:** O(1) excluding output

## C++ Solution

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> out;
        if (matrix.empty()) return out;
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        while (top <= bottom && left <= right) {
            for (int c = left; c <= right; ++c) out.push_back(matrix[top][c]);
            ++top;
            for (int r = top; r <= bottom; ++r) out.push_back(matrix[r][right]);
            --right;
            if (top <= bottom) {
                for (int c = right; c >= left; --c) out.push_back(matrix[bottom][c]);
                --bottom;
            }
            if (left <= right) {
                for (int r = bottom; r >= top; --r) out.push_back(matrix[r][left]);
                ++left;
            }
        }
        return out;
    }
};
```
