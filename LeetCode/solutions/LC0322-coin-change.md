# 322. Coin Change

**Lists:** Blind 75, Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

Given coin denominations and amount `amount`, return the fewest coins needed to make that amount, or `-1` if impossible.

## Intuition

`dp[a]` = min coins for amount `a`. For each amount, try every coin: `dp[a] = min(dp[a], dp[a-coin]+1)`.

## Approach

1. `dp` size `amount+1`, fill with `amount+1` (infinity).
2. `dp[0] = 0`.
3. For `a` from 1 to `amount`, for each coin if `a >= coin`, update `dp[a]`.

## Complexity

- **Time:** O(amount · |coins|)
- **Space:** O(amount)

## C++ Solution

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = amount + 1;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (int a = 1; a <= amount; ++a)
            for (int c : coins)
                if (c <= a) dp[a] = min(dp[a], dp[a - c] + 1);
        return dp[amount] == INF ? -1 : dp[amount];
    }
};
```
