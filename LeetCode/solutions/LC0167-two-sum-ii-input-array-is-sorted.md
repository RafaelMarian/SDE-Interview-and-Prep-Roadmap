# LC 167. Two Sum II - Input Array Is Sorted

**Lists:** Top 150
**Topic:** Two Pointers
**Difficulty:** Medium

## Problem
Given a 1-indexed sorted array `numbers` and target `target`, find two numbers such that they add up to `target`. Return the 1-indexed indices of the two numbers. Exactly one solution exists; you may not use the same element twice.

## Intuition
Sorted order invites two pointers at the ends: if sum is too small, move left right; if too large, move right left.

## Approach
1. Set `l = 0`, `r = n - 1`.
2. While `l < r`, compute `sum = numbers[l] + numbers[r]`.
3. If `sum == target`, return `{l + 1, r + 1}`.
4. Adjust `l` or `r` based on whether sum is below or above target.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = static_cast<int>(numbers.size()) - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                return {l + 1, r + 1};
            }
            if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
        return {};
    }
};
```
