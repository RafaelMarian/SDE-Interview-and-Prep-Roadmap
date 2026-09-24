# LC 210. Course Schedule II
**Lists:** Top 150  
**Topic:** Graph  
**Difficulty:** Medium

## Problem (short + example)

Return an ordering of courses to finish all prerequisites, or empty if impossible.

**Example:** `numCourses=4`, `[[1,0],[2,0],[3,1],[3,2]]` → `[0,1,2,3]` or `[0,2,1,3]`.

## Intuition

Topological sort: repeatedly take courses with no remaining prerequisites (Kahn’s algorithm).

## Approach

1. Build graph and indegree array.
2. Queue nodes with indegree 0; pop, append to order, decrease neighbors’ indegree.
3. If order size < `numCourses`, return `{}`; else return order.

## Complexity

- **Time:** O(V + E)  
- **Space:** O(V + E)

## C++ Solution

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            ++indeg[p[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indeg[i] == 0) q.push(i);
        vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : adj[u])
                if (--indeg[v] == 0) q.push(v);
        }
        return (int)order.size() == numCourses ? order : vector<int>{};
    }
};
```
