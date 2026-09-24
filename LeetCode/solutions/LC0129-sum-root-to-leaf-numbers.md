# LC 129. Sum Root to Leaf Numbers
**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Medium

## Problem (short + example)

Each root-to-leaf path forms a number (e.g. 1→2→3 is 123). Return the sum of all such numbers.

**Example:** `[1,2,3]` → 12 + 13 = 25.

## Intuition

Carry the number built so far down the tree; at leaves add it to a running total.

## Approach

1. DFS with current value `cur = parent * 10 + node->val`.
2. At leaf, add `cur` to `sum`.
3. Return accumulated `sum`.

## Complexity

- **Time:** O(n)  
- **Space:** O(h)

## C++ Solution

```cpp
class Solution {
    int dfs(TreeNode* node, int cur) {
        if (!node) return 0;
        cur = cur * 10 + node->val;
        if (!node->left && !node->right) return cur;
        return dfs(node->left, cur) + dfs(node->right, cur);
    }
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
```
