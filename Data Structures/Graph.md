# Graph

Nodes + edges. Represent with adjacency list. BFS/DFS are the interview bread and butter.

## Representation

```cpp
int n; // nodes 0..n-1
vector<vector<int>> adj(n);
adj[u].push_back(v);           // directed
adj[u].push_back(v);
adj[v].push_back(u);           // undirected: both ways
```

Weighted: `vector<vector<pair<int,int>>> adj;` // {to, weight}

## DFS / BFS

```cpp
void dfs(int u, vector<vector<int>>& adj, vector<bool>& seen) {
    seen[u] = true;
    for (int v : adj[u]) if (!seen[v]) dfs(v, adj, seen);
}

void bfs(int start, vector<vector<int>>& adj) {
    queue<int> q;
    vector<bool> seen(adj.size());
    q.push(start); seen[start] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) if (!seen[v]) {
            seen[v] = true; q.push(v);
        }
    }
}
```

## Core FAANG graph patterns

| Pattern | Use |
|---------|-----|
| BFS | shortest path unweighted, levels |
| DFS | components, cycle detect, path search |
| Topological sort Kahn / DFS | course schedule, build order |
| Union-Find | connected components, redundant connection |
| Dijkstra | weighted shortest path (non-neg) |
| Grid DFS/BFS | islands, flood fill, walls/gates |

## Topological sort (Kahn)

```cpp
vector<int> indeg(n);
for (auto& e : edges) indeg[e[1]]++;
queue<int> q;
for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
vector<int> order;
while (!q.empty()) {
    int u = q.front(); q.pop();
    order.push_back(u);
    for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
}
// cycle if order.size() != n
```

## Complexity
BFS/DFS: **O(V + E)**. Dijkstra with binary heap: **O((V + E) log V)**.

## Practice
| # | Problem |
|---|---------|
| LC 200 | Number of Islands |
| LC 207 | Course Schedule |
| LC 210 | Course Schedule II |
| LC 994 | Rotting Oranges |
| LC 127 | Word Ladder |
| LC 743 | Network Delay Time (Dijkstra) |

See [`Graph.cpp`](./Graph.cpp). Also [`UnionFind.cpp`](./UnionFind.cpp).
