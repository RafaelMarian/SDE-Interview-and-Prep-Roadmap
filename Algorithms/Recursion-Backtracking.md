# Recursion & Backtracking

Explore all candidates; **undo** after each choice. Subsets / permutations / combination problems.

## Template

```cpp
void backtrack(state) {
    if (goal reached) {
        record answer;
        return;
    }
    for (choice in choices) {
        if (!valid(choice)) continue;   // prune
        apply(choice);
        backtrack(new state);
        undo(choice);                   // unchoose
    }
}
```

## Classic families

| Family | Idea |
|--------|------|
| Subsets | include / skip each element |
| Permutations | swap or used[] mask |
| Combination sum | pick with reuse or not |
| N-Queens / Sudoku | place + conflict check |
| Word search | DFS on grid + mark visited |

## Pruning tips
- Sort + skip duplicates (`i > start && nums[i]==nums[i-1]`)
- Early stop when remaining sum < 0
- Bound checks before recurse

## Complexity
Often **O(2^n)** or **O(n!)** — still OK for n ≤ 15–20 with pruning.

## Practice
| # | Problem |
|---|---------|
| LC 78 | Subsets |
| LC 46 | Permutations |
| LC 39 | Combination Sum |
| LC 51 | N-Queens |
| LC 79 | Word Search |
| LC 22 | Generate Parentheses |

See [`Recursion-Backtracking.cpp`](./Recursion-Backtracking.cpp).
