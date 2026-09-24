# 73. Set Matrix Zeroes

**Lists:** Blind 75, Top Interview 150  
**Topic:** Matrix  
**Difficulty:** Medium  

## Problem

Given an `m x n` matrix, if an element is 0, set its entire row and column to 0. Do it in place.

## Intuition

Use first row and first column as markers for which rows/cols need zeroing, with special handling for `(0,0)` and first row/col zeros.

## Approach

1. Track if first row/col should be zeroed.
2. For `i,j` with `matrix[i][j]==0`, set `matrix[i][0]=0` and `matrix[0][j]=0`.
3. Process inner cells using markers, then zero first row/col if flagged.

## Complexity

- **Time:** O(m · n)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool zeroFirstRow = false, zeroFirstCol = false;
        for (int j = 0; j < n; ++j)
            if (matrix[0][j] == 0) zeroFirstRow = true;
        for (int i = 0; i < m; ++i)
            if (matrix[i][0] == 0) zeroFirstCol = true;
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        if (zeroFirstRow)
            for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        if (zeroFirstCol)
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
    }
};
```
