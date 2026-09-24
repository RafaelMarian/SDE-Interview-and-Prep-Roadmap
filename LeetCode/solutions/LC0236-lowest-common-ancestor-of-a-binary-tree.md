# LC 236. Lowest Common Ancestor of a Binary Tree
**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Medium

## Problem (short + example)

Given two nodes `p` and `q` in a binary tree, return their lowest common ancestor.

**Example:** Tree with nodes 5 and 1 → LCA is 3.

## Intuition

If current node is `p` or `q`, or splits the search (non-null from both subtrees), it is the LCA.

## Approach

1. Base: null → null; if node is `p` or `q` → node.
2. Recurse left and right.
3. If both sides non-null, current is LCA; else return the non-null side.

## Complexity

- **Time:** O(n)  
- **Space:** O(h)

## C++ Solution

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};
```
