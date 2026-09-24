# LC 46. Permutations

**Lists:** Top 150  
**Topic:** Backtracking  
**Difficulty:** Medium

## Problem
Return all permutations of a distinct-integer array.

## Intuition
Swap-based backtracking: fix position `start`, try every remaining index.

## Approach
1. At index `start`, swap with each `i >= start`, recurse `start+1`, swap back.  
2. When `start == n`, record permutation.

## Complexity
- Time: O(n · n!)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
    void dfs(vector<int>& nums, int start, vector<vector<int>>& ans) {
        if (start == (int)nums.size()) { ans.push_back(nums); return; }
        for (int i = start; i < (int)nums.size(); i++) {
            swap(nums[start], nums[i]);
            dfs(nums, start + 1, ans);
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums, 0, ans);
        return ans;
    }
};
```
