# LC 189. Rotate Array

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Medium

## Problem
Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

## Intuition
Rotating right by `k` is equivalent to reversing the whole array, then reversing the first `k` elements and the remaining `n - k` elements (with `k %= n`).

## Approach
1. Let `n = nums.size()`; set `k %= n`. If `k == 0`, return.
2. Reverse entire array.
3. Reverse `[0, k)`.
4. Reverse `[k, n)`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        k %= n;
        if (k == 0) {
            return;
        }
        auto rev = [&](int l, int r) {
            while (l < r) {
                swap(nums[l++], nums[r--]);
            }
        };
        rev(0, n - 1);
        rev(0, k - 1);
        rev(k, n - 1);
    }
};
```
