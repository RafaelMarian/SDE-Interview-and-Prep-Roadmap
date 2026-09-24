# LC 130. Surrounded Regions

**Lists:** Top 150  
**Topic:** Graph  
**Difficulty:** Medium

## Problem
Capture surrounded regions: flip `O` → `X` if not connected to the border. Border-connected `O`s stay.

## Intuition
DFS/BFS from all border `O`s and mark them safe (`#`). Then flip remaining `O`→`X` and `#`→`O`.

## Approach
1. For each border cell with `O`, DFS mark `#`.  
2. Scan board: `O`→`X`, `#`→`O`.

## Complexity
- Time: O(mn)
- Space: O(mn) worst recursion

## C++ Solution
```cpp
class Solution {
    void dfs(vector<vector<char>>& b, int r, int c) {
        int m = b.size(), n = b[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || b[r][c] != 'O') return;
        b[r][c] = '#';
        dfs(b, r + 1, c); dfs(b, r - 1, c);
        dfs(b, r, c + 1); dfs(b, r, c - 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0); dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(board, 0, j); dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
    }
};
```
