# LC 909. Snakes and Ladders

**Lists:** Top 150  
**Topic:** Graph BFS  
**Difficulty:** Medium

## Problem
`n×n` board with snakes/ladders. Start at 1, aim for `n²`. From square `curr`, can go to `curr+1..curr+6` (then snake/ladder). Min moves or −1.

## Intuition
BFS on squares 1..n². Map label → (r,c) carefully (boustrophedon).

## Approach
1. Flatten board destination array.  
2. BFS from 1; for each roll 1–6 take destination (snake/ladder if any).  
3. First reach n² → steps.

## Complexity
- Time: O(n²)
- Space: O(n²)

## C++ Solution
```cpp
class Solution {
    pair<int,int> idToRC(int id, int n) {
        int r = (id - 1) / n;
        int c = (id - 1) % n;
        if (r % 2) c = n - 1 - c;
        r = n - 1 - r;
        return {r, c};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> dest(n * n + 1, -1);
        for (int id = 1; id <= n * n; id++) {
            auto [r, c] = idToRC(id, n);
            if (board[r][c] != -1) dest[id] = board[r][c];
        }
        queue<int> q;
        vector<int> dist(n * n + 1, -1);
        q.push(1); dist[1] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == n * n) return dist[u];
            for (int d = 1; d <= 6 && u + d <= n * n; d++) {
                int v = u + d;
                if (dest[v] != -1) v = dest[v];
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return -1;
    }
};
```
