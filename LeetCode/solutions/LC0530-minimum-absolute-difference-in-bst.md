# LC 530. Minimum Absolute Difference in BST
**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Easy

## Problem (short + example)

In a BST, return the smallest absolute difference between any two node values.

**Example:** `[4,2,6,1,3]` → 1 (difference between 2 and 3 or 1 and 2).

## Intuition

Inorder traversal yields sorted values; minimum gap is minimum adjacent difference.

## Approach

1. Inorder DFS; track previous value and update `ans` with `min(ans, cur - prev)`.
2. Return `ans`.

## Complexity

- **Time:** O(n)  
- **Space:** O(h)

## C++ Solution

```cpp
class Solution {
    int ans = INT_MAX;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (prev) ans = min(ans, node->val - prev->val);
        prev = node;
        inorder(node->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
```
