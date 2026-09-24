# 300. Longest Increasing Subsequence

**Lists:** Blind 75, Top Interview 150  
**Topic:** 1D DP / Binary Search  
**Difficulty:** Medium  

## Problem

Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

## Intuition

Maintain `tails[i]` = smallest tail of an increasing subsequence of length `i+1`. For each `x`, binary search where to place `x` in `tails`.

## Approach

1. `vector<int> tails`.
2. For each `x`, `lower_bound` in `tails`; if at end, extend; else replace.

## Complexity

- **Time:** O(n log n)
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }
        return (int)tails.size();
    }
};
```
