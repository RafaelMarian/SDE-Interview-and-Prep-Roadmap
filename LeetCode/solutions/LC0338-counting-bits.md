# 338. Counting Bits

**Lists:** Blind 75, Top Interview 150  
**Topic:** Bit Manipulation / DP  
**Difficulty:** Easy  

## Problem

Given `n`, return an array `ans` of length `n + 1` where `ans[i]` is the number of `1`'s in the binary form of `i`.

## Intuition

`ans[i] = ans[i >> 1] + (i & 1)` — drop last bit, add parity of last bit.

## Approach

Fill `dp[0..n]` with recurrence starting `dp[0]=0`.

## Complexity

- **Time:** O(n)
- **Space:** O(n) output

## C++ Solution

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            dp[i] = dp[i >> 1] + (i & 1);
        return dp;
    }
};
```
