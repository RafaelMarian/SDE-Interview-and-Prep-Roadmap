# LC 199. Binary Tree Right Side View
**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Medium

## Problem (short + example)

Return values of nodes you would see from the right side (top to bottom).

**Example:** `[1,2,3,null,5,null,4]` → `[1,3,4]`.

## Intuition

Rightmost node at each depth wins; DFS visiting right before left records the first node at each depth.

## Approach

1. DFS with depth `d`; if `d == ans.size()`, push `node->val`.
2. Visit right child then left.
3. Return `ans`.

## Complexity

- **Time:** O(n)  
- **Space:** O(h)

## C++ Solution

```cpp
class Solution {
    vector<int> ans;
    void dfs(TreeNode* node, int d) {
        if (!node) return;
        if (d == (int)ans.size()) ans.push_back(node->val);
        dfs(node->right, d + 1);
        dfs(node->left, d + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
```
