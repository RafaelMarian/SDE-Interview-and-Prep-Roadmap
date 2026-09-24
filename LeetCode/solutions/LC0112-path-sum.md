# LC 112. Path Sum
**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Easy

## Problem (short + example)

Return whether the tree has a root-to-leaf path whose node values sum to `targetSum`.

**Example:** tree `[5,4,8,11,null,13,4,7,2,null,null,null,1]`, target 22 → `true` (5→4→11→2).

## Intuition

At each node subtract its value from the remaining target; at a leaf, remaining must be zero.

## Approach

1. DFS: if null, false; if leaf, return `target == node->val`.
2. Else recurse left/right with `target - node->val`.

## Complexity

- **Time:** O(n)  
- **Space:** O(h)

## C++ Solution

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right) return targetSum == root->val;
        int rem = targetSum - root->val;
        return hasPathSum(root->left, rem) || hasPathSum(root->right, rem);
    }
};
```
