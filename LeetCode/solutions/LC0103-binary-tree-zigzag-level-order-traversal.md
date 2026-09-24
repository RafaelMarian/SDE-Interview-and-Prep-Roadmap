# LC 103. Binary Tree Zigzag Level Order Traversal
**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Medium

## Problem (short + example)

Return level order traversal alternating left-to-right and right-to-left per level.

**Example:** `[3,9,20,null,null,15,7]` → `[[3],[20,9],[15,7]]`.

## Intuition

Same as level order BFS; reverse every other level’s vector before appending.

## Approach

1. BFS with queue; for each level collect values.
2. If level index is odd, reverse the level vector.
3. Push to answer.

## Complexity

- **Time:** O(n)  
- **Space:** O(w)

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int sz = (int)q.size();
            vector<int> level(sz);
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                int idx = leftToRight ? i : sz - 1 - i;
                level[idx] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            leftToRight = !leftToRight;
            res.push_back(std::move(level));
        }
        return res;
    }
};
```
