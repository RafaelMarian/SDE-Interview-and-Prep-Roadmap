# 261. Graph Valid Tree

**Lists:** Blind 75 (Premium)  
**Topic:** Graphs (Union-Find / cycle + connectivity)  
**Difficulty:** Medium  

## Problem

Given `n` nodes labeled `0 .. n-1` and undirected edges, return `true` if the edges form a valid tree (connected and acyclic).

## Intuition

A tree on `n` nodes has exactly `n - 1` edges, is connected, and has no cycles. Check `edges.size() == n - 1` and union-find finds no duplicate union (cycle).

## Approach

1. If `edges.size() != n - 1`, return false.
2. Union-find: if an edge connects already-connected nodes, cycle → false.
3. After all edges, one component remains → valid tree.

## Complexity

- **Time:** O(n · α(n))
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if ((int)edges.size() != n - 1) return false;
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (auto& e : edges) {
            int a = find(e[0]), b = find(e[1]);
            if (a == b) return false;
            parent[b] = a;
        }
        return true;
    }
};
```
