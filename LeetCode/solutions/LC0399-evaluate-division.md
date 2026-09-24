# LC 399. Evaluate Division
**Lists:** Top 150  
**Topic:** Graph  
**Difficulty:** Medium

## Problem (short + example)

Given equations like `a/b = 2.0`, answer queries `a/c` as products of known ratios, or `-1.0` if unknown.

**Example:** `[["a","b"],["b","c"]]`, values `[2.0,3.0]`, query `a/c` → `6.0`.

## Intuition

Build a weighted directed graph; each query is a path product from source to target.

## Approach

1. Build adjacency: `a→b` weight `v`, `b→a` weight `1/v`.
2. For each query, DFS/BFS from numerator with visited set; multiply weights along edges.
3. Return product or `-1.0`.

## Complexity

- **Time:** O(E + Q · (V + E))  
- **Space:** O(V + E)

## C++ Solution

```cpp
class Solution {
    bool dfs(const string& cur, const string& target,
             const unordered_map<string, vector<pair<string, double>>>& g,
             unordered_set<string>& vis, double& prod) {
        if (cur == target) return true;
        vis.insert(cur);
        auto it = g.find(cur);
        if (it == g.end()) return false;
        for (auto [nxt, w] : it->second) {
            if (vis.count(nxt)) continue;
            prod *= w;
            if (dfs(nxt, target, g, vis, prod)) return true;
            prod /= w;
        }
        return false;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> g;
        for (int i = 0; i < (int)equations.size(); ++i) {
            const string& a = equations[i][0], &b = equations[i][1];
            double v = values[i];
            g[a].push_back({b, v});
            g[b].push_back({a, 1.0 / v});
        }
        vector<double> res;
        for (auto& q : queries) {
            const string& s = q[0], &t = q[1];
            if (!g.count(s) || !g.count(t)) { res.push_back(-1.0); continue; }
            unordered_set<string> vis;
            double prod = 1.0;
            if (!dfs(s, t, g, vis, prod)) res.push_back(-1.0);
            else res.push_back(prod);
        }
        return res;
    }
};
```
