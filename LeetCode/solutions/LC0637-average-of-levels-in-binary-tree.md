# LC 637. Average of Levels in Binary Tree

**Lists:** Top 150  
**Topic:** Binary Tree BFS  
**Difficulty:** Easy

## Problem
Return the average value of nodes on each level.

## Intuition
BFS level order; sum / count per level.

## Approach
Queue BFS; for each level compute average as double.

## Complexity
- Time: O(n)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            double sum = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(sum / sz);
        }
        return ans;
    }
};
```
