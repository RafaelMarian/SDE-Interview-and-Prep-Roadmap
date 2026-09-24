# 123. Best Time to Buy and Sell Stock III

**Lists:** Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Hard  

## Problem

You are given an array `prices` where `prices[i]` is the price of a stock on day `i`. Find the maximum profit you can achieve with at most two transactions. You may not engage in multiple transactions simultaneously.

## Intuition

Track best profit after 0, 1, or 2 completed transactions, and whether you currently hold stock after first or second buy. State machine with `buy1, sell1, buy2, sell2`.

## Approach

1. Initialize `buy1 = buy2 = INT_MAX`, `sell1 = sell2 = 0`.
2. For each price `p`: update in order — `buy1 = min(buy1, p)`, `sell1 = max(sell1, p - buy1)`, `buy2 = min(buy2, p - sell1)`, `sell2 = max(sell2, p - buy2)`.
3. Return `sell2`.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int sell1 = 0, sell2 = 0;
        for (int p : prices) {
            buy1 = min(buy1, p);
            sell1 = max(sell1, p - buy1);
            buy2 = min(buy2, p - sell1);
            sell2 = max(sell2, p - buy2);
        }
        return sell2;
    }
};
```
