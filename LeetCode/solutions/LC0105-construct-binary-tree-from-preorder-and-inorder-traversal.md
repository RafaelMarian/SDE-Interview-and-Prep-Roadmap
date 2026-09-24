# LC 105. Construct Binary Tree from Preorder and Inorder Traversal
**Lists:** Blind 75 · Top 150  
**Topic:** Trees  
**Difficulty:** Medium

## Problem (short + example)

Build a binary tree from its preorder and inorder traversal arrays (unique values).

**Example:** `preorder = [3,9,20,15,7]`, `inorder = [9,3,15,20,7]` → tree with root 3.

## Intuition

Preorder's first element is the root. In inorder, everything left of the root is the left subtree; everything right is the right subtree. Recurse on those ranges.

## Approach

1. Map `inorder` value → index for O(1) root lookup.
2. Helper `(preL, preR, inL, inR)`: root = `preorder[preL]`; find `inRoot` in inorder.
3. Left size = `inRoot - inL`; build left then right subtrees.
4. Call helper on full array bounds.

## Complexity

- **Time:** O(n)  
- **Space:** O(n) for map + O(h) stack

## C++ Solution

```cpp
class Solution {
    std::unordered_map<int, int> idx;
    std::vector<int>& pre;
    std::vector<int>& in;

    TreeNode* build(int preL, int preR, int inL, int inR) {
        if (preL > preR) return nullptr;
        int rootVal = pre[preL];
        int inRoot = idx[rootVal];
        int leftSize = inRoot - inL;
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preL + 1, preL + leftSize, inL, inRoot - 1);
        root->right = build(preL + leftSize + 1, preR, inRoot + 1, inR);
        return root;
    }

public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
        : pre(preorder), in(inorder) {
        for (int i = 0; i < static_cast<int>(inorder.size()); ++i)
            idx[inorder[i]] = i;
        int n = static_cast<int>(preorder.size());
        return build(0, n - 1, 0, n - 1);
    }
};
```
