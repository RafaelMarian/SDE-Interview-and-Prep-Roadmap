# LC 1. Two Sum

**Lists:** Blind 75 · Top 150
**Topic:** Arrays & Hashing
**Difficulty:** Easy

## Problem
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`. Each input has exactly one solution. Example: `nums = [2,7,11,15], target = 9` → `[0,1]` because `nums[0] + nums[1] == 9`.

## Intuition
A brute-force pair check is O(n²). If we have already seen value `x` at index `i`, then `target - x` must appear later. A hash map from value to index lets us answer “have we seen the complement?” in O(1) per element.

## Approach
1. Iterate `nums` with index `i`.
2. Compute `need = target - nums[i]`.
3. If `need` is in the map, return `{map[need], i}`.
4. Otherwise store `nums[i] → i` in the map.
5. Return empty if no pair (LeetCode guarantees one solution).

## Complexity
- Time: O(n)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int need = target - nums[i];
            auto it = seen.find(need);
            if (it != seen.end()) {
                return {it->second, i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};
```
