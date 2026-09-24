# 70. Climbing Stairs

**Lists:** Blind 75, Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Easy  

## Problem

You can climb 1 or 2 steps at a time. Given `n` steps, return how many distinct ways to reach the top.

## Intuition

Ways to reach step `i` = ways to `i-1` + ways to `i-2` (Fibonacci).

## Approach

Iterate `i` from 2 to `n`, `dp[i] = dp[i-1] + dp[i-2]`, or use two variables rolling.

## Complexity

- **Time:** O(n)
- **Space:** O(1) with rolling

## C++ Solution

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int a = 1, b = 2;
        for (int i = 3; i <= n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
```
