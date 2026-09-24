# Dynamic Programming

Break problems into **overlapping subproblems** with optimal substructure. Store sub-answers to avoid exponential recomputation.

## Top-down vs bottom-up

| | Top-down (memo) | Bottom-up (tabulation) |
|---|-----------------|-------------------------|
| Style | DFS + `unordered_map` / vector | Nested loops fill table |
| Order | Natural recursion | Must respect dependency order |
| Space | Call stack + memo | Often can roll 1–2 rows |
| Interview | Quick to sketch | Shows you know transitions |

```cpp
// Top-down sketch
int dfs(int i, int j, vector<vector<int>>& memo) {
    if (base) return base_val;
    if (memo[i][j] != -1) return memo[i][j];
    return memo[i][j] = combine(dfs(...), dfs(...));
}
```

## 1D vs 2D patterns

**1D (`dp[i]`):** state depends on a prefix — climbing stairs, house robber, coin change, LIS (1D per index).

```cpp
dp[0] = base;
for (int i = 1; i <= n; i++)
    dp[i] = best over choices using dp[i - cost];
```

**2D (`dp[i][j]`):** two sequences or grid — LCS, edit distance, knapsack (items × capacity).

```cpp
for (int i = 1; i <= m; i++)
  for (int j = 1; j <= n; j++)
    if (match) dp[i][j] = dp[i-1][j-1] + 1;
    else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
```

**0/1 knapsack:** iterate `w` **descending** so each item used once.

## Decision table (what to optimize)

| Signal | Typical DP |
|--------|------------|
| Count ways | Sum transitions |
| Min / max cost | min / max |
| Yes / no feasible | boolean |
| Build sequence | store parent / backtrack |

## Pitfalls

- Wrong loop direction in 0/1 knapsack (ascending → unlimited knapsack).
- Off-by-one in indices vs string chars (`i-1` for `s[i-1]`).
- Forgetting base cases (`dp[0]`, empty string row).

## Practice

| # | Problem | Pattern |
|---|---------|---------|
| 70 | Climbing Stairs | 1D fib |
| 198 | House Robber | 1D max |
| 322 | Coin Change | unbounded min coins |
| 416 | Partition Equal Subset Sum | 0/1 knapsack |
| 1143 | LCS | 2D strings |
| 72 | Edit Distance | 2D strings |
| 300 | LIS | 1D O(n²) or patience O(n log n) |
| 62 | Unique Paths | grid DP |
