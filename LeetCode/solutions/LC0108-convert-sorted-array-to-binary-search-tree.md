# LC 108. Convert Sorted Array to Binary Search Tree

**Lists:** Top 150
**Topic:** Binary Tree / Divide and Conquer
**Difficulty:** Easy

## Problem
Given an integer array `nums` sorted in ascending order, convert it to a height-balanced binary search tree (each node’s two subtrees differ in height by at most one). Example: `nums = [-10,-3,0,5,9]` → a BST with root `0`, left `-3` (with `-10`), right `9` (with `5`).

## Intuition
The middle element of a sorted range is the BST root; recursively build left from the left half and right from the right half to keep balance.

## Approach
1. Helper `build(lo, hi)`: if `lo > hi`, return null.
2. `mid = lo + (hi - lo) / 2`, node value `nums[mid]`.
3. Left child from `[lo, mid-1]`, right from `[mid+1, hi]`.

## Complexity
- Time: O(n)
- Space: O(log n) recursion stack for balanced tree

## C++ Solution
```cpp
class Solution {
    TreeNode* build(const vector<int>& nums, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }
        int mid = lo + (hi - lo) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, lo, mid - 1);
        root->right = build(nums, mid + 1, hi);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, static_cast<int>(nums.size()) - 1);
    }
};
```
