# LC 226. Invert Binary Tree
**Lists:** Blind 75 · Top 150  
**Topic:** Trees  
**Difficulty:** Easy

## Problem (short + example)

Invert a binary tree (swap left and right children at every node).

**Example:**  
`4 / 2,7 / 1,3,6,9` → `4 / 7,2 / 9,6,3,1`.

## Intuition

Inversion is recursive: swap this node's children, then invert each subtree. DFS or BFS both work.

## Approach

1. If node is null, return.
2. Swap `left` and `right`.
3. Recursively invert left and right subtrees (or process with a queue).

## Complexity

- **Time:** O(n)  
- **Space:** O(h) recursion stack

## C++ Solution

```cpp
// struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```
