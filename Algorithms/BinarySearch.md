# Binary Search

Halve the search space each step. Works on **sorted arrays** or on a **monotonic answer space**.

## Classic template

```cpp
int binarySearch(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

## Lower bound (first ≥ target)

```cpp
int lowerBound(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size(); // hi is exclusive
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo; // may equal n
}
```

Prefer `std::lower_bound` / `std::upper_bound` when allowed.

## Binary search on answer

When “can we achieve X?” is monotonic:
1. Define `feasible(mid)`
2. Search min/max `mid` where feasible is true

Examples: koko eating bananas, capacity to ship packages, split array largest sum.

## Pitfalls
- Overflow: use `lo + (hi - lo) / 2`
- Off-by-one: decide inclusive vs exclusive `hi`
- Rotated array: identify which half is sorted

## Practice
| # | Problem |
|---|---------|
| LC 704 | Binary Search |
| LC 35 | Search Insert Position |
| LC 34 | First and Last Position |
| LC 33 | Search in Rotated Sorted Array |
| LC 875 | Koko Eating Bananas |
| LC 410 | Split Array Largest Sum |

See [`BinarySearch.cpp`](./BinarySearch.cpp).
