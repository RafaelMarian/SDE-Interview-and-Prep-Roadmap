# LC 222. Count Complete Tree Nodes
**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Easy

## Problem (short + example)

Count nodes in a complete binary tree in better than O(n) time.

**Example:** `[1,2,3,4,5,6]` → 6.

## Intuition

Compare left and right heights from the root. If equal, the last level is full on the left path; if not, recurse on the shorter side and add `2^h - 1` for the full subtree on the other side.

## Approach

1. `leftHeight`, `rightHeight` by walking only left/right spines.
2. If equal: return `2^h - 1`.
3. Else: `1 + count(left) + count(right)` on the smaller subtree only.

## Complexity

- **Time:** O(log² n)  
- **Space:** O(log n)

## C++ Solution

```cpp
class Solution {
    int height(TreeNode* node, bool goLeft) {
        int h = 0;
        while (node) {
            ++h;
            node = goLeft ? node->left : node->right;
        }
        return h;
    }

public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh = height(root->left, true);
        int rh = height(root->right, false);
        if (lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```
