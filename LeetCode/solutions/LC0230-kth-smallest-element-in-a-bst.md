# LC 230. Kth Smallest Element in a BST
**Lists:** Blind 75 · Top 150  
**Topic:** Trees  
**Difficulty:** Medium

## Problem (short + example)

Return the **k**th smallest value (1-indexed) in a BST.

**Example:** `[3,1,4,null,2]`, k = 1 → `1`.

## Intuition

Inorder traversal of a BST visits nodes in sorted order. Stop after visiting **k** nodes.

## Approach

1. Iterative inorder with a stack (or recursion with a counter).
2. Push left spine, pop, visit, go right.
3. When count reaches `k`, return that node's value.

## Complexity

- **Time:** O(h + k)  
- **Space:** O(h)

## C++ Solution

```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (--k == 0) return cur->val;
            cur = cur->right;
        }
        return -1;
    }
};
```
