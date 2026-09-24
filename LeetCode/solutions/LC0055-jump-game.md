# 55. Jump Game

**Lists:** Blind 75, Top Interview 150  
**Topic:** Greedy  
**Difficulty:** Medium  

## Problem

Each `nums[i]` is max jump length from index `i`. Return `true` if you can reach the last index starting at 0.

## Intuition

Track farthest reachable index. If `i > farthest`, stuck. Update `farthest = max(farthest, i + nums[i])`.

## Approach

Linear scan; return whether `farthest >= n-1` at end (or early if `farthest` passes end).

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (i > farthest) return false;
            farthest = max(farthest, i + nums[i]);
            if (farthest >= (int)nums.size() - 1) return true;
        }
        return true;
    }
};
```
