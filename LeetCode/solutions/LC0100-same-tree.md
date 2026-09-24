# LC 100. Same Tree
**Lists:** Blind 75 · Top 150  
**Topic:** Trees  
**Difficulty:** Easy

## Problem (short + example)

Given two binary trees, return whether they are structurally identical with equal values.

**Example:** `[1,2,3]` and `[1,2,3]` → `true`; `[1,2]` and `[1,null,2]` → `false`.

## Intuition

Two trees match iff roots match and left subtrees match and right subtrees match. Handle nulls explicitly.

## Approach

1. If both null → `true`; if one null → `false`.
2. If values differ → `false`.
3. Return `isSameTree(p->left, q->left) && isSameTree(p->right, q->right)`.

## Complexity

- **Time:** O(n)  
- **Space:** O(h)

## C++ Solution

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```
