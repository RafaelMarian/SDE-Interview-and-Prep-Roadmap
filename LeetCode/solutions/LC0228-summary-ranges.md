# LC 228. Summary Ranges

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Easy

## Problem
Given a sorted unique integer array `nums`, return the smallest sorted list of ranges that cover all numbers exactly. `"a->b"` for `a != b`, else `"a"`.

## Intuition
Scan for contiguous runs: when the next number is not `prev + 1`, close the current range and start a new one.

## Approach
1. For each start `i`, extend `j` while `nums[j + 1] == nums[j] + 1`.
2. Format range from `nums[i]` to `nums[j]`.
3. Set `i = j + 1`.

## Complexity
- Time: O(n)
- Space: O(1) extra excluding output

## C++ Solution
```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n;) {
            int j = i;
            while (j + 1 < n && nums[j + 1] == nums[j] + 1) {
                ++j;
            }
            if (i == j) {
                res.push_back(to_string(nums[i]));
            } else {
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            i = j + 1;
        }
        return res;
    }
};
```
