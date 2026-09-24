# 417. Pacific Atlantic Water Flow

**Lists:** Blind 75  
**Topic:** Graphs (multi-source DFS/BFS)  
**Difficulty:** Medium  

## Problem

Given an `m x n` matrix `heights` of non-negative integers, a cell can flow to another if the neighbor’s height is ≤ current. Water on the border flows into the Pacific (top/left) or Atlantic (bottom/right). Return all cells from which water can reach both oceans.

## Intuition

Reverse the flow: from ocean borders, climb to cells with height ≥ current. Cells reachable from both oceans are the answer.

## Approach

1. `pac` and `atl` boolean grids.
2. DFS from all Pacific border cells into higher-or-equal neighbors.
3. DFS from all Atlantic border cells similarly.
4. Collect `(r,c)` where both flags are true.

## Complexity

- **Time:** O(m · n)
- **Space:** O(m · n)

## C++ Solution

```cpp
class Solution {
    int m, n;
    vector<vector<int>>* H;
    const int dr[4] = {1, -1, 0, 0};
    const int dc[4] = {0, 0, 1, -1};

    void dfs(int r, int c, vector<vector<bool>>& reach) {
        reach[r][c] = true;
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n || reach[nr][nc]) continue;
            if ((*H)[nr][nc] < (*H)[r][c]) continue;
            dfs(nr, nc, reach);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        H = &heights;
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n)), atl(m, vector<bool>(n));

        for (int c = 0; c < n; ++c) {
            dfs(0, c, pac);
            dfs(m - 1, c, atl);
        }
        for (int r = 0; r < m; ++r) {
            dfs(r, 0, pac);
            dfs(r, n - 1, atl);
        }

        vector<vector<int>> ans;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (pac[r][c] && atl[r][c]) ans.push_back({r, c});
        return ans;
    }
};
```
