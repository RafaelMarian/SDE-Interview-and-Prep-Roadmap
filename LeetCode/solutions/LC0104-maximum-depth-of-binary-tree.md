# LC 104. Maximum Depth of Binary Tree
**Lists:** Blind 75 · Top 150  
**Topic:** Trees  
**Difficulty:** Easy

## Problem (short + example)

Return the maximum depth (number of nodes along the longest root-to-leaf path).

**Example:** `[3,9,20,null,null,15,7]` → depth `3`.

## Intuition

Depth at a node is `1 + max(depth(left), depth(right))`. Base case: empty tree has depth 0.

## Approach

1. If `root` is null, return 0.
2. Return `1 + max(maxDepth(left), maxDepth(right))`.

## Complexity

- **Time:** O(n)  
- **Space:** O(h)

## C++ Solution

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
```
