# LC 52. N-Queens II

**Lists:** Top 150  
**Topic:** Backtracking  
**Difficulty:** Hard

## Problem
Return the number of distinct solutions to the `n`-queens puzzle (place `n` queens on an `n×n` board so no two attack).

Example: `n = 4` → `2`

## Intuition
Place one queen per row. Track attacked columns and both diagonals with sets (or bitmasks). Count leaves of the search tree.

## Approach
1. DFS on `row`.  
2. For each `col` free of column/`diag`/`anti` conflicts, place and recurse.  
3. When `row == n`, increment answer.

## Complexity
- Time: O(n!)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
    int ans = 0;
    void dfs(int row, int n, unordered_set<int>& cols,
             unordered_set<int>& diag, unordered_set<int>& anti) {
        if (row == n) { ans++; return; }
        for (int col = 0; col < n; col++) {
            int d = row - col, a = row + col;
            if (cols.count(col) || diag.count(d) || anti.count(a)) continue;
            cols.insert(col); diag.insert(d); anti.insert(a);
            dfs(row + 1, n, cols, diag, anti);
            cols.erase(col); diag.erase(d); anti.erase(a);
        }
    }
public:
    int totalNQueens(int n) {
        unordered_set<int> cols, diag, anti;
        dfs(0, n, cols, diag, anti);
        return ans;
    }
};
```
