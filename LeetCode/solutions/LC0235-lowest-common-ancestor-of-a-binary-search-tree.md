# LC 235. Lowest Common Ancestor of a Binary Search Tree
**Lists:** Blind 75 · Top 150  
**Topic:** Trees  
**Difficulty:** Medium

## Problem (short + example)

Given a BST and two nodes `p` and `q`, return their lowest common ancestor (deepest node that has both as descendants).

**Example:** BST `[6,2,8,0,4,7,9,null,null,3,5]`, `p = 2`, `q = 8` → `6`.

## Intuition

In a BST, if both values are smaller than the current node, LCA is in the left subtree; if both larger, in the right; otherwise the current node splits them and is the LCA.

## Approach

1. Start at `root`.
2. If `p->val < root->val && q->val < root->val`, go left.
3. If both greater, go right.
4. Else return `root`.

## Complexity

- **Time:** O(h)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val)
                root = root->left;
            else if (p->val > root->val && q->val > root->val)
                root = root->right;
            else
                return root;
        }
        return nullptr;
    }
};
```
