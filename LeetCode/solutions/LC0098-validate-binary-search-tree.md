# LC 98. Validate Binary Search Tree
**Lists:** Blind 75 · Top 150  
**Topic:** Trees  
**Difficulty:** Medium

## Problem (short + example)

Determine if a binary tree is a valid BST: for every node, all keys in the left subtree are strictly less and all keys in the right subtree are strictly greater.

**Example:** `[2,1,3]` → `true`; `[5,1,4,null,null,3,6]` → `false`.

## Intuition

Pass down allowable `(min, max)` bounds for each node, or do inorder traversal and check strictly increasing values.

## Approach

1. DFS with `long long lo` and `hi` (use `LLONG_MIN` / `LLONG_MAX` at root).
2. If node is null → `true`; if `val` not in `(lo, hi)` → `false`.
3. Recurse left with `(lo, val)` and right with `(val, hi)`.

## Complexity

- **Time:** O(n)  
- **Space:** O(h)

## C++ Solution

```cpp
class Solution {
    bool valid(TreeNode* node, long long lo, long long hi) {
        if (!node) return true;
        if (node->val <= lo || node->val >= hi) return false;
        return valid(node->left, lo, node->val) && valid(node->right, node->val, hi);
    }

public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};
```
