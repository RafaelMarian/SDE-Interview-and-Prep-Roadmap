# LC 103. Binary Tree Zigzag Level Order Traversal

**Lists:** Top 150  
**Topic:** Binary Tree BFS  
**Difficulty:** Medium

## Problem
Return level-order traversal alternating left→right and right→left each level.

## Intuition
Standard BFS; reverse the level vector on odd depths.

## Approach
1. Queue BFS level by level.  
2. If level index is odd, reverse before pushing to answer.

## Complexity
- Time: O(n)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                int idx = leftToRight ? i : sz - 1 - i;
                level[idx] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(move(level));
            leftToRight = !leftToRight;
        }
        return ans;
    }
};
```
