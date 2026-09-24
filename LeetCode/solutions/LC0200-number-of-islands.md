# 200. Number of Islands

**Lists:** Blind 75, Top Interview 150  
**Topic:** Graphs (DFS/BFS on grid)  
**Difficulty:** Medium  

## Problem

Given an `m x n` 2D grid `grid` of `'1'` (land) and `'0'` (water), return the number of islands. An island is surrounded by water and formed by connecting adjacent lands horizontally or vertically.

## Intuition

Each unvisited `'1'` starts a new island; flood-fill it so we do not count it again.

## Approach

1. Scan every cell.
2. When `grid[r][c] == '1'`, increment count and DFS/BFS to sink the whole component (`'1'` → `'0'`).

## Complexity

- **Time:** O(m · n)
- **Space:** O(m · n) worst-case recursion or queue.

## C++ Solution

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        const int m = grid.size(), n = grid[0].size();
        int islands = 0;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (grid[r][c] == '1') {
                    ++islands;
                    dfs(grid, r, c);
                }
        return islands;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= (int)grid.size() || c >= (int)grid[0].size() || grid[r][c] != '1')
            return;
        grid[r][c] = '0';
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
};
```
