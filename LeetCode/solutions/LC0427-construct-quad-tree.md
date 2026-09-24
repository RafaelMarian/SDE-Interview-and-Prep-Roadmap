# LC 427. Construct Quad Tree

**Lists:** Top 150
**Topic:** Tree / Divide and Conquer
**Difficulty:** Medium

## Problem
Given a `n x n` matrix `grid` of `0` and `1`, represent it as a quad-tree. Each `Node` has `val`, `isLeaf`, and four children `topLeft`, `topRight`, `bottomLeft`, `bottomRight`. Leaf `val` is the uniform value; internal nodes have `val = 1` (LeetCode convention) and `isLeaf = false`. Example: uniform 1×1 grid → single leaf with `val = 1`.

## Intuition
Recursively split a square region into four quadrants; if all cells share the same value, return a leaf; otherwise build four subtrees and an internal node.

## Approach
1. `build(x, y, len)`: scan `len × len` subgrid starting at `(x,y)` for uniformity.
2. If uniform, return leaf with that value.
3. Else `half = len / 2`, create internal node and attach four recursive calls on quadrants.

## Complexity
- Time: O(n² log n) worst case with repeated scans; can be optimized with prefix sums
- Space: O(log n) recursion depth

## C++ Solution
```cpp
/*
// Definition for a Quad Tree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = topRight = bottomLeft = bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = topRight = bottomLeft = bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    bool uniform(const vector<vector<int>>& grid, int x, int y, int len) {
        int v = grid[x][y];
        for (int i = x; i < x + len; ++i) {
            for (int j = y; j < y + len; ++j) {
                if (grid[i][j] != v) {
                    return false;
                }
            }
        }
        return true;
    }

    Node* build(const vector<vector<int>>& grid, int x, int y, int len) {
        if (uniform(grid, x, y, len)) {
            return new Node(grid[x][y] == 1, true);
        }
        int half = len / 2;
        Node* tl = build(grid, x, y, half);
        Node* tr = build(grid, x, y + half, half);
        Node* bl = build(grid, x + half, y, half);
        Node* br = build(grid, x + half, y + half, half);
        return new Node(true, false, tl, tr, bl, br);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int n = static_cast<int>(grid.size());
        return build(grid, 0, 0, n);
    }
};
```
