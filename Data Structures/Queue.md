# Queue & Deque

FIFO (`queue`) and double-ended queue (`deque`). Core of BFS and sliding-window max.

## C++ containers

```cpp
std::queue<int> q;     // adapter over deque
q.push(x); q.front(); q.pop();

std::deque<int> dq;
dq.push_back(x); dq.push_front(x);
dq.pop_back(); dq.pop_front();
dq.front(); dq.back();
```

## When it shows up

- BFS on graphs / trees / grids
- Level-order traversal
- Sliding window maximum (monotonic deque)
- Circular queue / design problems
- 0-1 BFS (deque as priority)

## BFS template

```cpp
queue<int> q;
vector<int> dist(n, -1);
q.push(start);
dist[start] = 0;
while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```

## Monotonic deque (window max)

Store indices with decreasing values; front is always the max. See Sliding Window notes and `Queue.cpp`.

## Complexity
Enqueue/dequeue: **O(1)**. BFS: **O(V + E)**.

## Practice
| # | Problem |
|---|---------|
| LC 102 | Binary Tree Level Order Traversal |
| LC 239 | Sliding Window Maximum |
| LC 200 | Number of Islands (BFS) |
| LC 542 | 01 Matrix |
| LC 622 | Design Circular Queue |

See [`Queue.cpp`](./Queue.cpp).
