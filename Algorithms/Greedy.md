# Greedy

At each step, take the **locally best** choice hoping it yields a global optimum. Works only when the problem has **greedy choice property** and **optimal substructure** (not interchangeable with all DP problems).

## When greedy works

- Problem asks for **maximum / minimum** with matroid-like structure (intervals, deadlines).
- You can prove **exchange argument**: swapping any non-greedy choice for greedy never hurts.
- Sorting items by a key (ratio, end time, deadline) then one pass is a common pattern.

## Exchange argument (intuition)

For activity selection sorted by **end time**: suppose an optimal solution picks an interval that ends later than the greedy first pick. Replacing it with the earlier-ending greedy interval frees at least as much room → no fewer intervals can fit. Hence greedy is optimal.

## Templates

**Furthest reach (jump game):**

```cpp
int reach = 0;
for (int i = 0; i < n; i++) {
    if (i > reach) return false;
    reach = max(reach, i + nums[i]);
}
```

**Intervals — sort by end, take if start >= lastEnd:**

```cpp
sort by end;
for (iv : intervals)
    if (iv.start >= lastEnd) { take; lastEnd = iv.end; }
```

**Fractional knapsack — sort by value/weight descending.**

## Greedy vs DP

| | Greedy | DP |
|---|--------|-----|
| Proof | Often needs exchange / matroid | Recurrence always valid |
| Time | Usually O(n log n) from sort | Often O(n²) or O(n·W) |
| Example | Activity selection | 0/1 knapsack (no fractions) |

## Pitfalls

- Applying greedy to **0/1 knapsack** (need DP).
- Wrong sort key (start vs end vs ratio).
- Jump game II needs different greedy (min jumps), not just reachability.

## Practice

| # | Problem | Greedy idea |
|---|---------|-------------|
| 55 | Jump Game | max reach |
| 45 | Jump Game II | BFS / greedy jumps |
| 435 | Non-overlapping Intervals | sort by end |
| 253 | Meeting Rooms II | sort + heap (or sweep) |
| 134 | Gas Station | total sum + reset start |
| 455 | Assign Cookies | sort both |
| 621 | Task Scheduler | freq + formula |
| 860 | Lemonade Change | simulate |
