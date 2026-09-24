# LC 74. Search a 2D Matrix
**Lists:** Top 150  
**Topic:** Binary Search  
**Difficulty:** Medium

## Problem (short + example)

Matrix sorted row-wise and column-wise (first of row > last of previous row). Find `target`.

**Example:** `matrix=[[1,3,5,7],[10,11,16,20],[23,30,34,60]]`, `target=3` → true.

## Intuition

Treat as a sorted 1D array of size `m*n`; index `i` maps to `matrix[i/n][i%n]`.

## Approach

1. Binary search on virtual index `0..m*n-1`.
2. Compare `matrix[mid/n][mid%n]` with `target`.
3. Return true/false.

## Complexity

- **Time:** O(log(mn))  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = (int)matrix.size(), n = (int)matrix[0].size();
        int lo = 0, hi = m * n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int val = matrix[mid / n][mid % n];
            if (val == target) return true;
            if (val < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
};
```
