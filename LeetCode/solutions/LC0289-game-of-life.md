# LC 289. Game of Life

**Lists:** Top 150
**Topic:** Matrix
**Difficulty:** Medium

## Problem
Given an `m × n` board of cells (0 dead, 1 live), apply Conway's rules simultaneously: live cell with 2–3 live neighbors survives; dead cell with exactly 3 live neighbors becomes live. Update in-place.

## Intuition
Encode next state in extra bits: use 2 for next-live and 4 for next-dead so neighbor counts still read the original live bit (`& 1`).

## Approach
1. Eight directions for neighbors; for each cell count live neighbors (`board[nr][nc] & 1`).
2. Apply rules; set bit 1 if next state is live.
3. Second pass: shift all values right by 1 to finalize.

## Complexity
- Time: O(m · n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = static_cast<int>(board.size());
        int n = static_cast<int>(board[0].size());
        const int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int live = 0;
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        live += board[nr][nc] & 1;
                    }
                }
                if (board[r][c] & 1) {
                    if (live == 2 || live == 3) {
                        board[r][c] |= 2;
                    }
                } else if (live == 3) {
                    board[r][c] |= 2;
                }
            }
        }
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                board[r][c] >>= 1;
            }
        }
    }
};
```
