# 207. Course Schedule

**Lists:** Blind 75, Top Interview 150  
**Topic:** Graphs (cycle detection / topological sort)  
**Difficulty:** Medium  

## Problem

There are `numCourses` labeled `0 .. numCourses-1` and prerequisites `prerequisites[i] = [a, b]` meaning take `b` before `a`. Return `true` if you can finish all courses (no cycle in the prerequisite graph).

## Intuition

Prerequisites form a directed graph; finishing all courses is possible iff the graph is a DAG. Detect cycle with Kahn’s algorithm (in-degree BFS) or DFS coloring.

## Approach

1. Build adjacency list and in-degree array.
2. Enqueue all nodes with in-degree 0.
3. Pop, decrement neighbors’ in-degrees; enqueue when zero.
4. If processed count equals `numCourses`, no cycle.

## Complexity

- **Time:** O(V + E)
- **Space:** O(V + E)

## C++ Solution

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            ++indeg[p[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indeg[i] == 0) q.push(i);
        int taken = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++taken;
            for (int v : adj[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }
        return taken == numCourses;
    }
};
```
