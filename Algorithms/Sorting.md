# Sorting

Know implementations of **merge / quick / heap** and when to use `std::sort`.

## Complexity & properties

| Algorithm | Avg | Worst | Space | Stable |
|-----------|-----|-------|-------|--------|
| Merge Sort | n log n | n log n | O(n) | Yes |
| Quick Sort | n log n | n² | O(log n) | No* |
| Heap Sort | n log n | n log n | O(1) | No |
| `std::sort` | n log n | n log n | — | No (introsort) |
| `std::stable_sort` | n log n | n log n | O(n) | Yes |
| Counting / Radix | n + k | — | O(n+k) | Yes |

\* can be made stable with care; interview default is unstable.

## When which

- **Interview default:** `std::sort` / explain quick or merge
- **Stable needed:** merge or `stable_sort`
- **Linked list:** merge sort shines
- **Nearly sorted:** insertion sort conceptually
- **Integers small range:** counting sort

## Quick select
Same partition as quicksort → Kth element average **O(n)**. C++: `std::nth_element`.

## Practice
| # | Problem |
|---|---------|
| LC 912 | Sort an Array |
| LC 215 | Kth Largest (quickselect / heap) |
| LC 56 | Merge Intervals |
| LC 179 | Largest Number (custom comparator) |

See [`Sorting.cpp`](./Sorting.cpp).
