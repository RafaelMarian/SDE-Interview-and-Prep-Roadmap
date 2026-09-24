# 323. Number of Connected Components in an Undirected Graph

**Lists:** Blind 75 (Premium)  
**Topic:** Graphs (Union-Find / DFS)  
**Difficulty:** Medium  

## Problem

Given `n` nodes labeled `0 .. n-1` and undirected edges, return the number of connected components.

## Intuition

Each edge merges two components; start with `n` components and subtract one per successful union. Alternatively, count roots after DFS.

## Approach

**Union-Find:** Initialize parent[i]=i, count=n. For each edge `(u,v)`, if `find(u) != find(v)`, union and decrement count.

## Complexity

- **Time:** O(n + e · α(n)) with union-find
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
    vector<int> parent, rank_;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b]) ++rank_[a];
        return true;
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank_.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
        int components = n;
        for (auto& e : edges)
            if (unite(e[0], e[1])) --components;
        return components;
    }
};
```
