# Union-Find (Disjoint Set Union)

Tracks disjoint sets with near-O(1) “same component?” and “merge” — after path compression + union by rank.

## API

```cpp
struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false; // already connected
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};
```

## When it shows up

- Number of connected components / provinces
- Redundant connection / cycle in undirected graph
- Accounts merge / friend circles
- Kruskal MST
- Grid problems after mapping cells → ids

## Complexity
Almost **O(1)** per op (inverse Ackermann α(n)).

## Practice
| # | Problem |
|---|---------|
| LC 547 | Number of Provinces |
| LC 684 | Redundant Connection |
| LC 721 | Accounts Merge |
| LC 1319 | Number of Operations to Make Network Connected |

See [`UnionFind.cpp`](./UnionFind.cpp).
