# LC 572. Subtree of Another Tree
**Lists:** Blind 75 · Top 150  
**Topic:** Trees  
**Difficulty:** Easy

## Problem (short + example)

Return `true` if `subRoot` is a subtree of `root` (same structure and values at some node of `root`).

**Example:** `root = [3,4,5,1,2]`, `subRoot = [4,1,2]` → `true`.

## Intuition

At every node of `root`, check whether the tree rooted there equals `subRoot` (same as LC 100). DFS explores all candidate roots.

## Approach

1. If `subRoot` is null → `true`; if `root` is null → `false`.
2. If trees match at `root` → `true`.
3. Return `isSubtree(left, subRoot) || isSubtree(right, subRoot)`.

## Complexity

- **Time:** O(n × m) worst case  
- **Space:** O(h)

## C++ Solution

```cpp
class Solution {
    bool same(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        if (a->val != b->val) return false;
        return same(a->left, b->left) && same(a->right, b->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;
        if (same(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
```
