# LC 106. Construct Binary Tree from Inorder and Postorder Traversal
**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Medium

## Problem (short + example)

Build the unique binary tree from its inorder and postorder traversal arrays.

**Example:** inorder `[9,3,15,20,7]`, postorder `[9,15,7,20,3]` → tree with root 3, left 9, right 20, etc.

## Intuition

Last element of postorder is the root; locate it in inorder to split left/right subtrees.

## Approach

1. Map inorder values to indices.
2. Recurse on postorder range: root = last index; split inorder at root.
3. Build right subtree first (postorder processes right before left at the end).

## Complexity

- **Time:** O(n)  
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
    unordered_map<int, int> idx;
    int build(vector<int>& in, vector<int>& post, int inLo, int inHi, int postLo, int postHi) {
        if (inLo > inHi) return -1;
        int rootVal = post[postHi];
        int mid = idx[rootVal];
        int leftSize = mid - inLo;
        TreeNode* node = new TreeNode(rootVal);
        node->left = buildTreeFrom(in, post, inLo, mid - 1, postLo, postLo + leftSize - 1);
        node->right = buildTreeFrom(in, post, mid + 1, inHi, postLo + leftSize, postHi - 1);
        return node; // placeholder - fix below
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        idx.clear();
        for (int i = 0; i < (int)inorder.size(); ++i) idx[inorder[i]] = i;
        return buildHelper(inorder, postorder, 0, (int)inorder.size() - 1, 0, (int)postorder.size() - 1);
    }
private:
    TreeNode* buildHelper(vector<int>& in, vector<int>& post, int inLo, int inHi, int postLo, int postHi) {
        if (inLo > inHi) return nullptr;
        int rootVal = post[postHi];
        int mid = idx[rootVal];
        int leftSize = mid - inLo;
        TreeNode* node = new TreeNode(rootVal);
        node->left = buildHelper(in, post, inLo, mid - 1, postLo, postLo + leftSize - 1);
        node->right = buildHelper(in, post, mid + 1, inHi, postLo + leftSize, postHi - 1);
        return node;
    }
};
```
