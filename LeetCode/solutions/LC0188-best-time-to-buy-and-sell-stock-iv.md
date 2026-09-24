# 188. Best Time to Buy and Sell Stock IV

**Lists:** Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Hard  

## Problem

You are given an integer array `prices` where `prices[i]` is the price of a stock on day `i`, and an integer `k`. Find the maximum profit you can achieve with at most `k` transactions.

## Intuition

Generalization of at-most-2-transactions DP: `dp[t][0]` = max profit with at most `t` transactions and not holding; `dp[t][1]` = holding. Roll over days. If `k >= n/2`, unlimited trades → sum all positive deltas.

## Approach

1. If `k >= n/2`, greedy sum of upward moves.
2. Else `vector<int> hold(k+1, INT_MIN), cash(k+1, 0)`.
3. For each price, for `t` from 1 to k: update `hold[t] = max(hold[t], cash[t-1]-p)`, `cash[t] = max(cash[t], hold[t]+p)`.
4. Return `cash[k]`.

## Complexity

- **Time:** O(n × k)
- **Space:** O(k)

## C++ Solution

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i)
                if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
            return profit;
        }
        vector<int> cash(k + 1, 0), hold(k + 1, INT_MIN);
        for (int p : prices) {
            for (int t = 1; t <= k; ++t) {
                hold[t] = max(hold[t], cash[t - 1] - p);
                cash[t] = max(cash[t], hold[t] + p);
            }
        }
        return cash[k];
    }
};
```
