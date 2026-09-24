# Heap / Priority Queue

Binary heap gives O(1) peek of min/max and O(log n) insert/pop. Top-K and merge problems.

## C++ API

```cpp
// max-heap by default
std::priority_queue<int> maxh;

// min-heap
std::priority_queue<int, std::vector<int>, std::greater<int>> minh;

maxh.push(x);
maxh.top();
maxh.pop();
```

Custom comparator: `priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);`

## When it shows up

- Kth largest / top-K frequent
- Merge K sorted lists
- Meeting rooms / CPU scheduling (sweep + heap)
- Dijkstra’s algorithm
- Median of stream (two heaps)

## Pattern: Kth largest
Keep a **min-heap of size K**; top is the Kth largest.

```cpp
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int x : nums) {
        minh.push(x);
        if ((int)minh.size() > k) minh.pop();
    }
    return minh.top();
}
```

## Complexity
Build heap: O(n). Insert/pop: O(log n). Top-K over n: **O(n log k)**.

## Practice
| # | Problem |
|---|---------|
| LC 215 | Kth Largest Element |
| LC 347 | Top K Frequent Elements |
| LC 23 | Merge K Sorted Lists |
| LC 295 | Find Median from Data Stream |
| LC 253 | Meeting Rooms II |

See [`Heap.cpp`](./Heap.cpp).
