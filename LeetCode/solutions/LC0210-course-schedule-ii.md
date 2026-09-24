# LC 210. Course Schedule II

**Lists:** Top 150  
**Topic:** Graph / Topological Sort  
**Difficulty:** Medium

## Problem
Return a valid course order given prerequisites `[a,b]` meaning b → a. Empty if cycle.

## Intuition
Kahn's algorithm: BFS on zero indegree nodes; shrink indegrees.

## Approach
1. Build adj + indegree.  
2. Queue all indegree 0.  
3. Pop, append to order, reduce neighbors.  
4. If order size != n, cycle → `{}`.

## Complexity
- Time: O(V + E)
- Space: O(V + E)

## C++ Solution
```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses);
        for (auto& e : prerequisites) {
            adj[e[1]].push_back(e[0]);
            indeg[e[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indeg[i] == 0) q.push(i);
        vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u])
                if (--indeg[v] == 0) q.push(v);
        }
        if ((int)order.size() != numCourses) return {};
        return order;
    }
};
```
