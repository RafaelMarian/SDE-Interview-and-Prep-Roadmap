# LC 199. Binary Tree Right Side View

**Lists:** Top 150  
**Topic:** Binary Tree BFS  
**Difficulty:** Medium

## Problem
Return the values of nodes visible from the right side (rightmost node per level).

## Intuition
BFS level order; last node of each level is the right-side view.

## Approach
Queue BFS; for each level, record the last popped node's value.

## Complexity
- Time: O(n)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                if (i == sz - 1) ans.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};
```
