# LC 219. Contains Duplicate II

**Lists:** Top 150
**Topic:** Hash Map
**Difficulty:** Easy

## Problem
Given integer array `nums` and integer `k`, return true if there exist distinct indices `i` and `j` such that `nums[i] == nums[j]` and `abs(i - j) <= k`.

## Intuition
Sliding window of size `k`: map each value to its latest index; if the same value appears again within `k` steps, return true.

## Approach
1. Map value → last index seen.
2. For each index `i`, if `nums[i]` was seen and `i - last <= k`, return true.
3. Update map with `i`.
4. Return false.

## Complexity
- Time: O(n)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> last;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            auto it = last.find(nums[i]);
            if (it != last.end() && i - it->second <= k) {
                return true;
            }
            last[nums[i]] = i;
        }
        return false;
    }
};
```
