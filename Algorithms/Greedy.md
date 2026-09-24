# Greedy

Make the locally optimal choice at each step. Works only when that leads to a global optimum (prove via exchange / staying ahead).

## When to try greedy

- Interval scheduling / merging
- Jump game / reachability
- Assign cookies / candy / tasks with cooldown
- Huffman / activity selection
- Minimum platforms / meeting rooms (sort + sweep)

If you cannot argue correctness, fall back to DP.

## Core patterns

### Jump Game — farthest reach
```cpp
bool canJump(vector<int>& a) {
    int far = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (i > far) return false;
        far = max(far, i + a[i]);
    }
    return true;
}
```

### Interval: sort by end, take non-overlapping
```cpp
sort(intervals.begin(), intervals.end(),
     [](auto& x, auto& y){ return x[1] < y[1]; });
```

### Fractional knapsack
Sort by value/weight density; take whole items then fraction.

## Practice
| # | Problem |
|---|---------|
| LC 55 | Jump Game |
| LC 45 | Jump Game II |
| LC 435 | Non-overlapping Intervals |
| LC 253 | Meeting Rooms II |
| LC 134 | Gas Station |
| LC 455 | Assign Cookies |

See [`Greedy.cpp`](./Greedy.cpp).
