# LC 124. Binary Tree Maximum Path Sum
**Lists:** Blind 75 · Top 150  
**Topic:** Trees  
**Difficulty:** Hard

## Problem (short + example)

A path is any sequence of nodes where each pair of adjacent nodes has an edge. Path sum is the sum of node values. Return the maximum path sum (path may start/end at any node).

**Example:** `[-10,9,20,null,null,15,7]` → `42` (path `15 → 20 → 7`).

## Intuition

At each node, the best "through" path uses left + node + right (for global max). The best path you can extend upward is `node + max(leftGain, rightGain, 0)`—never take a negative child branch.

## Approach

1. DFS `gain(node)`: max sum of a path starting at `node` going down one side.
2. Update global max with `node->val + max(0, left) + max(0, right)`.
3. Return `node->val + max({0, left, right})`.

## Complexity

- **Time:** O(n)  
- **Space:** O(h)

## C++ Solution

```cpp
class Solution {
    int best = INT_MIN;

    int gain(TreeNode* node) {
        if (!node) return 0;
        int left = std::max(0, gain(node->left));
        int right = std::max(0, gain(node->right));
        best = std::max(best, node->val + left + right);
        return node->val + std::max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        gain(root);
        return best;
    }
};
```
