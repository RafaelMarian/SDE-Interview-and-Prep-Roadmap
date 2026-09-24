# LC 169. Majority Element

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Easy

## Problem
Given an array `nums` of size `n`, return the majority element — the element that appears more than `⌊n / 2⌋` times. You may assume the majority element always exists.

## Intuition
Boyer–Moore voting: cancel pairs of different elements; the survivor must be the majority if one exists.

## Approach
1. Track candidate `cand` and count `cnt`.
2. For each value, if `cnt == 0`, set `cand = x` and `cnt = 1`; else increment or decrement `cnt` when `x` matches or differs.
3. Return `cand`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = 0, cnt = 0;
        for (int x : nums) {
            if (cnt == 0) {
                cand = x;
                cnt = 1;
            } else if (x == cand) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return cand;
    }
};
```
