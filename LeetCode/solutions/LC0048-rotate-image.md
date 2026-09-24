# 48. Rotate Image

**Lists:** Blind 75, Top Interview 150  
**Topic:** Matrix  
**Difficulty:** Medium  

## Problem

Given an `n x n` matrix, rotate it 90 degrees clockwise in place.

## Intuition

Transpose then reverse each row, or rotate layer by layer.

## Approach

1. Transpose: swap `matrix[i][j]` with `matrix[j][i]` for `j > i`.
2. Reverse each row.

## Complexity

- **Time:** O(n²)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
        for (int i = 0; i < n; ++i)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
```
