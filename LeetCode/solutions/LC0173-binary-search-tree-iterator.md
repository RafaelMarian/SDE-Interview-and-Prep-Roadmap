# LC 173. Binary Search Tree Iterator
**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Medium

## Problem (short + example)

Implement an iterator over a BST with `next()` (smallest remaining) and `hasNext()` in average O(1) time.

**Example:** Inorder sequence `7, 3, 9, ...` emitted one step at a time.

## Intuition

Simulate inorder with a stack: push left spine, pop to get next, then push left spine of right child.

## Approach

1. Constructor pushes all left nodes from root.
2. `next`: pop top, push left chain of its right child, return value.
3. `hasNext`: stack non-empty.

## Complexity

- **Time:** O(1) amortized per `next`  
- **Space:** O(h)

## C++ Solution

```cpp
class BSTIterator {
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) { pushLeft(root); }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushLeft(node->right);
        return node->val;
    }

    bool hasNext() { return !st.empty(); }
};
```
