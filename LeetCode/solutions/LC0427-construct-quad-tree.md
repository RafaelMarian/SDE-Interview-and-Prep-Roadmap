# LC 427. Construct Quad Tree

**Lists:** Top 150  
**Topic:** Divide & Conquer  
**Difficulty:** Medium

## Problem
Build a QuadTree from an `n×n` binary grid (`n` power of 2).

## Intuition
If a region is uniform, make a leaf. Else split into 4 quadrants and recurse.

## Approach
`build(r0,c0,size)`: scan region; if all equal → leaf; else 4 children of size/2.

## Complexity
- Time: O(n² log n) naive scan per region (can optimize with prefix sums)
- Space: O(n²) nodes worst

## C++ Solution
```cpp
// Definition for a QuadTree node.
// class Node { public: bool val; bool isLeaf; Node* topLeft; Node* topRight; Node* bottomLeft; Node* bottomRight; ...};

class Solution {
    Node* build(vector<vector<int>>& g, int r, int c, int len) {
        bool same = true;
        int v = g[r][c];
        for (int i = r; i < r + len && same; i++)
            for (int j = c; j < c + len; j++)
                if (g[i][j] != v) { same = false; break; }
        if (same) return new Node(v, true);
        int half = len / 2;
        Node* node = new Node(true, false);
        node->topLeft = build(g, r, c, half);
        node->topRight = build(g, r, c + half, half);
        node->bottomLeft = build(g, r + half, c, half);
        node->bottomRight = build(g, r + half, c + half, half);
        return node;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};
```
