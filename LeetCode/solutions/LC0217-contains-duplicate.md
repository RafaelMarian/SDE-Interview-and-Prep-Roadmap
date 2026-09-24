# LC 217. Contains Duplicate

**Lists:** Blind 75 · Top 150
**Topic:** Arrays & Hashing
**Difficulty:** Easy

## Problem
Given an integer array `nums`, return `true` if any value appears at least twice, otherwise `false`. Example: `nums = [1,2,3,1]` → `true`.

## Intuition
Duplicates are exactly the case where we insert a number into a set and find it was already there. One pass with an `unordered_set` is enough.

## Approach
1. Create an empty `unordered_set<int>`.
2. For each `x` in `nums`, if `x` is in the set, return `true`.
3. Insert `x` into the set.
4. Return `false` after the loop.

## Complexity
- Time: O(n) average
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (!seen.insert(x).second) {
                return true;
            }
        }
        return false;
    }
};
```
