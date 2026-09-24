# LC 347. Top K Frequent Elements

**Lists:** Blind 75 · Top 150
**Topic:** Arrays & Hashing
**Difficulty:** Medium

## Problem
Given an integer array `nums` and integer `k`, return the `k` most frequent elements in any order. Example: `nums = [1,1,1,2,2,3], k = 2` → `[1,2]`.

## Intuition
First count frequencies. Bucket sort by frequency: index `i` holds all numbers that appear exactly `i` times. Scan buckets from high frequency downward until we collect `k` values.

## Approach
1. Count frequencies with `unordered_map<int,int>`.
2. Create `vector<vector<int>>` buckets of size `n + 1`.
3. Place each distinct number into `buckets[freq]`.
4. Iterate `i` from `n` down to `1`, append bucket elements to answer until size `k`.

## Complexity
- Time: O(n)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            ++freq[x];
        }
        int n = static_cast<int>(nums.size());
        vector<vector<int>> buckets(n + 1);
        for (const auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }
        vector<int> result;
        for (int c = n; c >= 1 && static_cast<int>(result.size()) < k; --c) {
            for (int x : buckets[c]) {
                result.push_back(x);
                if (static_cast<int>(result.size()) == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
```
