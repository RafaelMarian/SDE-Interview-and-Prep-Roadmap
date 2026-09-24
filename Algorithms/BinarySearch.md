# Binary Search

Search on **sorted** (or **monotonic**) data in `O(log n)` by halving the search space each step.

## When to reach for it

- Sorted array / answer space is monotonic (first `x` where predicate holds)
- "Minimize maximum", "maximize minimum" with feasibility check
- Rotated sorted array, peak finding, sqrt / integer division

**Not** binary search: unsorted data without a predicate on indices; use hashing or two pointers instead.

---

## Templates

### Classic (exact match, closed interval)

```cpp
int lo = 0, hi = n - 1;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] == target) return mid;
    if (nums[mid] < target) lo = mid + 1;
    else hi = mid - 1;
}
return -1;
```

### Lower bound (first `i` with `nums[i] >= target`)

Half-open `[lo, hi)` → insert position, first `>=`.

```cpp
int lo = 0, hi = n;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] < target) lo = mid + 1;
    else hi = mid;
}
return lo;
```

**First / last occurrence:** first = lower bound; last = upper_bound style (`nums[mid] <= target` → `lo = mid + 1`) then `lo - 1`.

### Rotated sorted array

Identify which half is sorted; check if `target` lies in that half.

---

## Pitfalls

| Issue | Fix |
|--------|-----|
| Overflow in `mid` | Use `lo + (hi - lo) / 2` |
| Off-by-one (`<=` vs `<`) | Pick one invariant: closed `[lo,hi]` vs half-open `[lo,hi)` |
| Duplicates in rotated search | Often need separate "find min pivot" pass |
| Infinite loop | Ensure `lo`/`hi` always moves |

---

## Practice (LeetCode)

| # | Problem | Idea |
|---|---------|------|
| 704 | Binary Search | Classic |
| 35 | Search Insert Position | `lower_bound` |
| 34 | Find First and Last Position | Two bounds |
| 33 | Search in Rotated Sorted Array | Which half is sorted |
| 153 | Find Minimum in Rotated Sorted Array | Pivot |
| 4 | Median of Two Sorted Arrays | BS on partition |
| 875 | Koko Eating Bananas | BS on answer |
| 1011 | Capacity To Ship Packages | BS on answer |
