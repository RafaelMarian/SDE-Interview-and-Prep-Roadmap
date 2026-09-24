# LC 49. Group Anagrams

**Lists:** Blind 75 · Top 150
**Topic:** Arrays & Hashing
**Difficulty:** Medium

## Problem
Given an array of strings `strs`, group the anagrams together. Return the groups in any order. Example: `strs = ["eat","tea","tan","ate","nat","bat"]` → `[["bat"],["nat","tan"],["ate","eat","tea"]]`.

## Intuition
All strings in a group share the same multiset of characters. A canonical key—sorted string or a 26-letter count signature—maps each word to its group in O(1) average hash map time.

## Approach
1. Use `unordered_map<string, vector<string>>` keyed by canonical form.
2. For each string, build key (sorted copy or count signature).
3. Append the string to `groups[key]`.
4. Collect all group vectors into the result.

## Complexity
- Time: O(n · k log k) with sort keys (k = max string length); O(n · k) with count keys
- Space: O(n · k) for stored strings

## C++ Solution
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        vector<vector<string>> result;
        result.reserve(groups.size());
        for (auto& [_, bucket] : groups) {
            result.push_back(std::move(bucket));
        }
        return result;
    }
};
```
