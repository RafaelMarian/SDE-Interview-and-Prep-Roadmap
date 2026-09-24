# Dynamic Programming

Break a problem into overlapping subproblems; store answers instead of recomputing.

## Two styles

| Style | How | Tip |
|-------|-----|-----|
| Top-down (memo) | Recursion + cache | Easy to write from recurrence |
| Bottom-up (tabulation) | Iterative table | Often better constants / clearer complexity |

## Pattern map (FAANG)

| Pattern | Example | State idea |
|---------|---------|------------|
| 1D linear | Climbing stairs, House Robber | `dp[i]` from `i-1`, `i-2` |
| 0/1 Knapsack | Subset sum, Target sum | `dp[i][w]` take / skip item |
| Unbounded knapsack | Coin change | reuse item in inner loop |
| LCS / Edit distance | Strings | `dp[i][j]` on two prefixes |
| LIS | Longest increasing | O(n²) DP or O(n log n) tails |
| Grid paths | Unique paths, min path sum | `dp[r][c]` from top/left |
| Interval DP | Burst balloons | longer intervals from shorter |
| State compression | TSP small n | bitmask `dp[mask][i]` |

## Decision checklist
1. What is the **answer for a smaller input**?
2. What **choices** at this step?
3. Can I define `dp[...]` so choices transition cleanly?
4. Base cases? Dimensionality? Can I compress space?

## Pitfalls
- Off-by-one on indexing / base cases
- Wrong loop order for knapsack (0/1 needs reverse capacity loop in 1D)
- Confusing subsequence (non-contiguous) vs subarray

## Practice
| # | Problem |
|---|---------|
| LC 70 | Climbing Stairs |
| LC 198 | House Robber |
| LC 322 | Coin Change |
| LC 300 | Longest Increasing Subsequence |
| LC 1143 | Longest Common Subsequence |
| LC 416 | Partition Equal Subset Sum |
| LC 62 | Unique Paths |
| LC 72 | Edit Distance |

See [`DynamicProgramming.cpp`](./DynamicProgramming.cpp).
