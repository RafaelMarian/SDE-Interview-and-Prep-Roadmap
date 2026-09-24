# LC 128. Longest Consecutive Sequence

**Lists:** Blind 75 · Top 150
**Topic:** Arrays & Hashing
**Difficulty:** Medium

## Problem
Given an unsorted array `nums`, return the length of the longest consecutive elements sequence in O(n) time. Example: `nums = [100,4,200,1,3,2]` → `3` (sequence `1,2,3`).

## Intuition
Put all numbers in a set. A number starts a sequence only if `num - 1` is absent, avoiding redundant walks. From each start, count upward while `num + 1` exists.

## Approach
1. Insert all values into `unordered_set<int>`.
2. For each `num` in the set, skip if `num - 1` exists.
3. Walk `cur = num, cur+1, ...` while in set, track length.
4. Update global maximum length.

## Complexity
- Time: O(n) — each element visited in at most one walk
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int best = 0;
        for (int num : numSet) {
            if (numSet.count(num - 1)) {
                continue;
            }
            int cur = num;
            int len = 1;
            while (numSet.count(cur + 1)) {
                ++cur;
                ++len;
            }
            best = max(best, len);
        }
        return best;
    }
};
```
