# LC 909. Snakes and Ladders

**Lists:** Top 150
**Topic:** Graphs (BFS)
**Difficulty:** Medium

## Problem
On an `n x n` board numbered 1 to n² in boustrophedon order, start at square 1. Each move goes 1–6 squares forward. Snakes and ladders jump to another square. Return the minimum moves to reach n², or `-1` if impossible. Example: board with ladder 1→38 and snake 35→11 may take 4 moves.

## Intuition
Treat each square as a node; from square `s`, edges to `s+1..s+6` (after applying snake/ladder destination). Unweighted shortest path is BFS.

## Approach
1. Map label `v` to board coordinates (reverse boustrophedon row indexing).
2. BFS from 1 with distance array; enqueue neighbors for dice 1..6 while label ≤ n².
3. If cell has snake/ladder ≠ -1, jump to that label once.
4. Return distance at n² or `-1`.

## Complexity
- Time: O(n²)
- Space: O(n²)

## C++ Solution
```cpp
class Solution {
    int labelToRow(int label, int n) {
        int r = (label - 1) / n;
        return n - 1 - r;
    }

    int labelToCol(int label, int n) {
        int r = (label - 1) / n;
        int c = (label - 1) % n;
        if ((n - 1 - r) % 2 == 1) {
            c = n - 1 - c;
        }
        return c;
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = static_cast<int>(board.size());
        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == n * n) {
                return dist[cur];
            }
            for (int dice = 1; dice <= 6; ++dice) {
                int next = cur + dice;
                if (next > n * n) {
                    break;
                }
                int r = labelToRow(next, n);
                int c = labelToCol(next, n);
                if (board[r][c] != -1) {
                    next = board[r][c];
                }
                if (dist[next] == -1) {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};
```
