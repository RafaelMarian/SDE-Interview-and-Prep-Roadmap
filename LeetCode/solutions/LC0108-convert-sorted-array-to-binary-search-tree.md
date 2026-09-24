# LC 108. Convert Sorted Array to Binary Search Tree

**Lists:** Top 150  
**Topic:** Divide & Conquer / BST  
**Difficulty:** Easy

## Problem
Convert a sorted ascending array into a height-balanced BST.

## Intuition
Middle element is root; recurse on left and right halves → balanced.

## Approach
`build(lo, hi)`: mid = (lo+hi)/2; root = nums[mid]; left = build(lo,mid-1); right = build(mid+1,hi).

## Complexity
- Time: O(n)
- Space: O(log n) recursion

## C++ Solution
```cpp
class Solution {
    TreeNode* build(vector<int>& nums, int lo, int hi) {
        if (lo > hi) return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, lo, mid - 1);
        root->right = build(nums, mid + 1, hi);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, (int)nums.size() - 1);
    }
};
```
