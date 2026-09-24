# LC 121. Best Time to Buy and Sell Stock

**Lists:** Blind 75 · Top 150
**Topic:** Sliding Window
**Difficulty:** Easy

## Problem
Given an array `prices` where `prices[i]` is the stock price on day `i`, choose one day to buy and a later day to sell to maximize profit. Return the maximum profit; if none, return `0`. Example: `prices = [7,1,5,3,6,4]` → `5` (buy at `1`, sell at `6`).

## Intuition
The best sell on any day is that day's price minus the minimum price seen on any prior day. Track the running minimum buy price and the best profit so far in one pass.

## Approach
1. Set `minPrice = INT_MAX`, `maxProfit = 0`.
2. For each `price`, update `minPrice = min(minPrice, price)`.
3. Update `maxProfit = max(maxProfit, price - minPrice)`.
4. Return `maxProfit`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};
```
