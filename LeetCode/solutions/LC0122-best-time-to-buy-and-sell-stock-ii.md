# LC 122. Best Time to Buy and Sell Stock II

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Medium

## Problem
Given an array `prices` where `prices[i]` is the price on day `i`, maximize profit. You may complete as many transactions as you like (buy one and sell one share multiple times), but you cannot hold more than one share at a time.

## Intuition
Any upward move from day `i` to `i + 1` can be captured as a transaction; summing all positive day-over-day deltas equals maximum profit.

## Approach
1. Initialize `profit = 0`.
2. For `i` from 1 to `n - 1`, add `max(0, prices[i] - prices[i - 1])` to `profit`.
3. Return `profit`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < static_cast<int>(prices.size()); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
```
