# 133. Clone Graph

**Lists:** Blind 75, Top Interview 150  
**Topic:** Graphs (BFS/DFS + hash map)  
**Difficulty:** Medium  

## Problem

Given a reference to a node in a connected undirected graph, return a deep copy of the graph. Each node contains a value and a list of neighbors.

## Intuition

Map each original node to its clone. Traverse neighbors; create clones on first visit and wire `neighbors` from the map.

## Approach

1. If `node` is null, return null.
2. Use `unordered_map<Node*, Node*>` for old → new.
3. BFS (or DFS): dequeue a node, ensure clone exists, for each neighbor create clone if missing and append to clone’s `neighbors`, enqueue neighbor if new.

## Complexity

- **Time:** O(V + E)
- **Space:** O(V)

## C++ Solution

```cpp
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> clones;
        queue<Node*> q;
        clones[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for (Node* nei : cur->neighbors) {
                if (!clones.count(nei)) {
                    clones[nei] = new Node(nei->val);
                    q.push(nei);
                }
                clones[cur]->neighbors.push_back(clones[nei]);
            }
        }
        return clones[node];
    }
};
```
