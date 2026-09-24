# Binary Tree & BST

Hierarchical structure. Almost every FAANG onsite has a tree question.

## Node

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

## Traversals

| Order | Pattern | Use |
|-------|---------|-----|
| Preorder | root → L → R | serialize, copy |
| Inorder | L → root → R | BST → sorted |
| Postorder | L → R → root | delete, compute from children |
| Level-order | BFS queue | level problems |

## DFS templates

```cpp
void dfs(TreeNode* node) {
    if (!node) return;
    // pre: use node->val
    dfs(node->left);
    // in
    dfs(node->right);
    // post
}
```

Height / depth problems: recurse on children, combine with `1 + max(...)`.

## BST property
Left subtree < node < right subtree. Search / insert / delete in O(h); balanced → O(log n).

## Classic patterns
- Max depth, diameter, invert, path sum
- Lowest Common Ancestor (BST vs binary tree)
- Validate BST (bounds, not only local)
- Serialize / deserialize
- Build tree from preorder+inorder

## Complexity
Visit each node once: **O(n)** time, **O(h)** recursion stack (worst O(n) skewed).

## Practice
| # | Problem |
|---|---------|
| LC 104 | Maximum Depth of Binary Tree |
| LC 226 | Invert Binary Tree |
| LC 102 | Level Order Traversal |
| LC 98 | Validate Binary Search Tree |
| LC 236 | Lowest Common Ancestor |
| LC 124 | Binary Tree Maximum Path Sum |

See [`BinaryTree.cpp`](./BinaryTree.cpp).
