# LC 102. Binary Tree Level Order Traversal
**Lists:** Blind 75 · Top 150  
**Topic:** Trees  
**Difficulty:** Medium

## Problem (short + example)

Return level-order traversal as a list of levels (left to right within each level).

**Example:** `[3,9,20,null,null,15,7]` → `[[3],[9,20],[15,7]]`.

## Intuition

BFS with a queue: process all nodes at the current frontier, collect their values into one level, then enqueue children.

## Approach

1. If empty, return `{}`.
2. Queue with `root`; while queue not empty:
   - Record `size = queue.size()`, build level vector.
   - Pop `size` nodes, push values, enqueue children.
3. Append each level to answer.

## Complexity

- **Time:** O(n)  
- **Space:** O(n) for queue/output

## C++ Solution

```cpp
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        if (!root) return ans;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = static_cast<int>(q.size());
            std::vector<int> level;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(std::move(level));
        }
        return ans;
    }
};
```
