# LC 130. Surrounded Regions
**Lists:** Top 150  
**Topic:** Graph  
**Difficulty:** Medium

## Problem (short + example)

Capture all `'O'` regions fully surrounded by `'X'`. Border-connected `'O'` stay.

**Example:** board with interior `O` islands flipped to `X`.

## Intuition

Only cells unreachable from the border should flip. Mark border-connected `O` first, then flip remaining `O`.

## Approach

1. DFS/BFS from every `O` on the border; mark as safe (e.g. `'S'`).
2. Scan board: `'O'` → `'X'`, `'S'` → `'O'`.

## Complexity

- **Time:** O(m · n)  
- **Space:** O(m · n) worst-case recursion/stack

## C++ Solution

```cpp
class Solution {
    int m, n;
    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != 'O') return;
        board[r][c] = 'S';
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

public:
    void solve(vector<vector<char>>& board) {
        m = (int)board.size();
        if (!m) return;
        n = (int)board[0].size();
        for (int i = 0; i < m; ++i) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = board[i][j] == 'S' ? 'O' : 'X';
    }
};
```
