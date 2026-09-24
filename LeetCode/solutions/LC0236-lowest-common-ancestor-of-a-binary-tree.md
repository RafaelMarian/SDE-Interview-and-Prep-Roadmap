# LC 236. Lowest Common Ancestor of a Binary Tree

**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Medium

## Problem
Find LCA of nodes `p` and `q` in a binary tree (not necessarily BST).

## Intuition
If root is p or q, return root. Recurse left/right; if both sides non-null, root is LCA; else return the non-null side.

## Approach
Post-order DFS as above.

## Complexity
- Time: O(n)
- Space: O(h)

## C++ Solution
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* L = lowestCommonAncestor(root->left, p, q);
        TreeNode* R = lowestCommonAncestor(root->right, p, q);
        if (L && R) return root;
        return L ? L : R;
    }
};
```
