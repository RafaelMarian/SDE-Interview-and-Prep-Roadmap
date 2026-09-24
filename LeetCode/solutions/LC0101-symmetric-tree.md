# LC 101. Symmetric Tree
**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Easy

## Problem (short + example)

Return whether a binary tree is a mirror of itself around its center.

**Example:** `[1,2,2,3,4,4,3]` → `true`; `[1,2,2,null,3,null,3]` → `false`.

## Intuition

Two subtrees are symmetric if left’s left matches right’s right and left’s right matches right’s left.

## Approach

1. DFS helper `isMirror(a, b)`: both null → true; one null or vals differ → false.
2. Recurse on `(a->left, b->right)` and `(a->right, b->left)`.
3. Call `isMirror(root, root)`.

## Complexity

- **Time:** O(n)  
- **Space:** O(h)

## C++ Solution

```cpp
class Solution {
    bool mirror(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b || a->val != b->val) return false;
        return mirror(a->left, b->right) && mirror(a->right, b->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return mirror(root, root);
    }
};
```
