# Recursion & Backtracking

Explore a **decision tree**: at each step choose an option, recurse, then **undo** the choice. Same skeleton covers subsets, permutations, combinations, and constraint puzzles (N-Queens, Sudoku).

## Template: choose / explore / unchoose

```cpp
void backtrack(State& state, int index /* or row */) {
    if (base_case_satisfied) {
        record_answer();
        return;
    }
    for (auto choice : valid_choices_at(index)) {
        if (!is_valid(choice)) continue;   // prune
        apply(choice);
        backtrack(state, next_index);
        undo(choice);
    }
}
```

| Pattern | Loop variable | Reuse elements? |
|---------|---------------|-----------------|
| Subsets | index `i`, take or skip | — |
| Combinations | `start` index | No reuse (combinations) |
| Combination sum | `start`, same `i` allowed | Yes |
| Permutations | all `i` + `used[]` | Each once |

## Pruning tips

- **Sort + skip duplicates:** if `candidates[i] == candidates[i-1]` and `i > start`, continue.
- **Early exit:** `remain < 0` in combination sum; invalid partial board in N-Queens.
- **Constraint propagation:** track cols/diagonals with sets or bitmasks instead of scanning all rows.
- **Branch ordering:** try most constrained variable first (Sudoku).

## Pitfalls

- Forgetting to **pop** / reset `used` after recursion.
- Copying large `path` into answer instead of pushing a copy at leaf only.
- Infinite recursion: always advance index or depth.

## Practice

| # | Problem | Pattern |
|---|---------|---------|
| 78 | Subsets | take / skip |
| 90 | Subsets II | + duplicate skip |
| 46 | Permutations | used array |
| 39 | Combination Sum | reuse from `i` |
| 40 | Combination Sum II | no reuse + dup skip |
| 77 | Combinations | `start` only forward |
| 51 | N-Queens | row-by-row placement |
| 79 | Word Search | grid DFS + unmark |
