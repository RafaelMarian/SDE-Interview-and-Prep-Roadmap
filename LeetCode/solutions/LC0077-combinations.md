# LC 77. Combinations

**Lists:** Top 150  
**Topic:** Backtracking  
**Difficulty:** Medium

## Problem
Return all combinations of `k` numbers chosen from `1..n`.

## Intuition
Backtrack choosing the next number ≥ previous+1 until path size is `k`.

## Approach
DFS from `start`; push `i`, recurse `i+1`, pop. Stop when path size == k.

## Complexity
- Time: O(C(n,k) · k)
- Space: O(k)

## C++ Solution
```cpp
class Solution {
    void dfs(int start, int n, int k, vector<int>& path, vector<vector<int>>& ans) {
        if ((int)path.size() == k) { ans.push_back(path); return; }
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(i + 1, n, k, path, ans);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(1, n, k, path, ans);
        return ans;
    }
};
```
