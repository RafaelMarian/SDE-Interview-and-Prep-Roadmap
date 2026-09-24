# LC 530. Minimum Absolute Difference in BST

**Lists:** Top 150  
**Topic:** BST  
**Difficulty:** Easy

## Problem
Return the minimum absolute difference between values of any two different nodes in a BST.

## Intuition
Inorder traversal of BST is sorted; min diff is between consecutive inorder values.

## Approach
Inorder DFS; track previous value; update `min(|cur - prev|)`.

## Complexity
- Time: O(n)
- Space: O(h)

## C++ Solution
```cpp
class Solution {
    int prev = -1, ans = INT_MAX;
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (prev != -1) ans = min(ans, node->val - prev);
        prev = node->val;
        inorder(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
```
