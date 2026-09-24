# 39. Combination Sum

**Lists:** Blind 75, Top Interview 150  
**Topic:** Backtracking  
**Difficulty:** Medium  

## Problem

Given an array of distinct integers `candidates` and a target integer `target`, return all unique combinations of candidates where the chosen numbers sum to `target`. The same number may be chosen unlimited times. Two combinations are unique if the frequency of at least one candidate differs.

## Intuition

This is unconstrained subset sum with reuse. Sorting helps pruning: once a candidate exceeds the remaining target, all later candidates are too large. At each index we can take the same index again (reuse) or move forward.

## Approach

1. Sort `candidates`.
2. DFS from index `start` with remaining `target`.
3. If `target == 0`, record the current path.
4. For `i` from `start` to end: if `candidates[i] > target`, break; push `candidates[i]`, recurse with same `i` and `target - candidates[i]`, then pop.

## Complexity

- **Time:** O(2^target) in worst case (branching on sums); tighter bound depends on candidates and target.
- **Space:** O(target / min(candidates)) recursion depth, excluding output.

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        dfs(candidates, target, 0, path, result);
        return result;
    }

    void dfs(const vector<int>& candidates, int target, int start,
             vector<int>& path, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < (int)candidates.size(); ++i) {
            if (candidates[i] > target) break;
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, path, result);
            path.pop_back();
        }
    }
};
```
