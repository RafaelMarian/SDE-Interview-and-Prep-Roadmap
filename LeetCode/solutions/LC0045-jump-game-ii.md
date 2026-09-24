# LC 45. Jump Game II

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Medium

## Problem
Given a 0-indexed array of non-negative integers `nums`, you start at index 0. Each `nums[i]` is the maximum jump length from `i`. Return the minimum number of jumps to reach the last index. You may assume you can always reach the last index.

## Intuition
Greedy BFS layers: track the farthest index reachable with the current number of jumps and the farthest reachable with one more jump. When the scan index hits the end of the current layer, increment jumps.

## Approach
1. If `n <= 1`, return 0.
2. Maintain `jumps`, `end` (current layer boundary), and `far` (best reach in next layer).
3. Scan `i` from 0 to `n - 2`, update `far = max(far, i + nums[i])`.
4. When `i == end`, increment `jumps`, set `end = far`.
5. Return `jumps`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 1) {
            return 0;
        }
        int jumps = 0, end = 0, far = 0;
        for (int i = 0; i < n - 1; ++i) {
            far = max(far, i + nums[i]);
            if (i == end) {
                ++jumps;
                end = far;
            }
        }
        return jumps;
    }
};
```
