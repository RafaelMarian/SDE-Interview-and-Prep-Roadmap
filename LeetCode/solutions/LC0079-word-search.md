# 79. Word Search

**Lists:** Blind 75, Top Interview 150  
**Topic:** Backtracking  
**Difficulty:** Medium  

## Problem

Given an `m x n` grid of characters `board` and a string `word`, return `true` if `word` exists in the grid. Letters must be adjacent horizontally or vertically, and the same cell may not be used twice in one path.

## Intuition

Walk the word character by character from every cell. Mark visited cells temporarily (e.g. `'#'`) to avoid reuse, then restore on backtrack.

## Approach

1. For each cell `(r, c)`, run DFS with index `k` into `word`.
2. Base: `k == word.size()` → success.
3. Check bounds, board char matches `word[k]`, and cell not blocked.
4. Mark cell, explore four neighbors with `k + 1`, unmark on return.

## Complexity

- **Time:** O(m · n · 4^L) where L is word length (branching up to 4).
- **Space:** O(L) recursion stack.

## C++ Solution

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size(), n = board[0].size();
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (dfs(board, word, 0, r, c)) return true;
        return false;
    }

    bool dfs(vector<vector<char>>& board, const string& word, int k, int r, int c) {
        if (k == (int)word.size()) return true;
        if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()) return false;
        if (board[r][c] != word[k]) return false;

        char saved = board[r][c];
        board[r][c] = '#';
        const int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
        for (int d = 0; d < 4; ++d)
            if (dfs(board, word, k + 1, r + dr[d], c + dc[d])) {
                board[r][c] = saved;
                return true;
            }
        board[r][c] = saved;
        return false;
    }
};
```
