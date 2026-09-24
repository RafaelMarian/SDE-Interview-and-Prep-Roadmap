# LC 637. Average of Levels in Binary Tree
**Lists:** Top 150  
**Topic:** Binary Tree  
**Difficulty:** Easy

## Problem (short + example)

Return the average value of nodes at each depth level.

**Example:** `[3,9,20,null,null,15,7]` → `[3.0, 14.5, 11.0]`.

## Intuition

BFS processes one level at a time; sum values and divide by count.

## Approach

1. Queue with root; while queue not empty, process `size` nodes at current level.
2. Accumulate sum and count; push average to result.
3. Enqueue children.

## Complexity

- **Time:** O(n)  
- **Space:** O(w)

## C++ Solution

```cpp
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = (int)q.size();
            long long sum = 0;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back((double)sum / sz);
        }
        return res;
    }
};
```
