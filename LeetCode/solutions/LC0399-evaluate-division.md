# LC 399. Evaluate Division

**Lists:** Top 150  
**Topic:** Graph  
**Difficulty:** Medium

## Problem
Equations `a/b = k` given. Answer queries `c/d` (or −1 if unknown).

## Intuition
Build weighted directed graph: `a→b` weight k, `b→a` weight 1/k. Query = path product via DFS/BFS.

## Approach
1. Build adj map `string → vector<{nei, w}>`.  
2. For each query, DFS/BFS from start seeking end, multiply edge weights.  
3. Missing node → −1.

## Complexity
- Time: O(E · Q) naive DFS
- Space: O(E)

## C++ Solution
```cpp
class Solution {
    bool dfs(const string& u, const string& target, double prod,
             unordered_map<string, vector<pair<string,double>>>& g,
             unordered_set<string>& seen, double& ans) {
        if (u == target) { ans = prod; return true; }
        seen.insert(u);
        for (auto& [v, w] : g[u]) {
            if (seen.count(v)) continue;
            if (dfs(v, target, prod * w, g, seen, ans)) return true;
        }
        return false;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> g;
        for (int i = 0; i < (int)equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            g[a].push_back({b, values[i]});
            g[b].push_back({a, 1.0 / values[i]});
        }
        vector<double> res;
        for (auto& q : queries) {
            if (!g.count(q[0]) || !g.count(q[1])) { res.push_back(-1.0); continue; }
            unordered_set<string> seen;
            double ans = -1.0;
            dfs(q[0], q[1], 1.0, g, seen, ans);
            res.push_back(ans);
        }
        return res;
    }
};
```
