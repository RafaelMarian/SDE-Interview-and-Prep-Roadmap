# LC 114. Flatten Binary Tree to Linked List
**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Medium

## Problem (short + example)

Flatten the tree to a linked list in preorder using only the `right` pointer (like `1 → 2 → 3 → 4 → 5 → 6`).

**Example:** Given preorder-shaped tree, mutate in place to a right-only list.

## Intuition

Preorder is root, then entire left subtree, then entire right. Attach left subtree’s tail to right child, then move left chain to the right.

## Approach

1. While `cur` exists: if `cur->left`, find rightmost of left subtree.
2. Link that node’s `right` to `cur->right`; move `cur->left` to `cur->right`; clear `cur->left`.
3. `cur = cur->right`.

## Complexity

- **Time:** O(n)  
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* tail = cur->left;
                while (tail->right) tail = tail->right;
                tail->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};
```
