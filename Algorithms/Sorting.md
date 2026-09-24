# Sorting

Ordering elements for search, greedy, or two-pointer setups. Know **how** classic sorts work and **when** to use each.

## Complexity & stability

| Algorithm | Time (avg) | Time (worst) | Space | Stable |
|-----------|------------|--------------|-------|--------|
| Merge sort | O(n log n) | O(n log n) | O(n) | Yes |
| Quick sort | O(n log n) | O(n²) | O(log n) stack | No |
| Heap sort | O(n log n) | O(n log n) | O(1) | No |
| `std::sort` | O(n log n) | O(n log n)* | O(log n) | No |
| `std::stable_sort` | O(n log n) | O(n log n) | O(n) | Yes |

\*Intro sort; avoids quadratic worst case in practice.

## When which sort

- **Interview implementation:** merge (divide & conquer), quick (partition), heap (priority / k-th element mindset).
- **Production C++:** `std::sort` / `std::stable_sort` — tuned introsort / mergesort hybrid.
- **Need stability** (equal keys keep relative order): merge sort or `std::stable_sort`.
- **Linked list:** merge sort natural fit.
- **Nearly sorted / small n:** insertion sort can win (often inside `std::sort` for tiny ranges).
- **Counting / radix:** integers in bounded range → O(n).

## Merge sort template

```cpp
void mergeSort(vector<int>& a, int l, int r, vector<int>& buf) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid, buf);
    mergeSort(a, mid + 1, r, buf);
    // merge a[l..mid] and a[mid+1..r] into buf, copy back
}
```

## Quick sort template

```cpp
int partition(vector<int>& a, int l, int r) {
    int pivot = a[r], i = l;
    for (int j = l; j < r; j++)
        if (a[j] <= pivot) swap(a[i++], a[j]);
    swap(a[i], a[r]);
    return i;
}
```

## Pitfalls

- Quick sort worst case on sorted input with bad pivot → random pivot or median-of-three.
- Merge sort needs extra O(n) memory.
- Comparator for `std::sort` must define **strict weak ordering** (`!(a<b && b<a)`).

## Practice

| # | Problem | Sorting angle |
|---|---------|----------------|
| 912 | Sort an Array | Implement or use STL |
| 215 | Kth Largest Element | Quick select / heap |
| 148 | Sort List | Merge on linked list |
| 56 | Merge Intervals | Sort by start |
| 252 | Meeting Rooms | Sort by time |
