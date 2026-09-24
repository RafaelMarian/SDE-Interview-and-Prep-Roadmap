# LC 295. Find Median from Data Stream
**Lists:** Blind 75 · Top 150  
**Topic:** Heap  
**Difficulty:** Hard

## Problem (short + example)

Implement `MedianFinder` that supports `addNum(num)` and `findMedian()` for a growing integer stream.

**Example:** Add `1`, `2` → median `1.5`; add `3` → median `2.0`.

## Intuition

Keep the lower half in a max-heap and the upper half in a min-heap so the tops are the middle elements. Balance sizes so `low.size() >= high.size()` and `low.size() - high.size() <= 1`.

## Approach

1. **addNum:** push to `low` (max-heap); push popped max from `low` to `high` (min-heap); if `low` smaller than `high`, move top of `high` back to `low`.
2. **findMedian:** if equal sizes, average of both tops; else top of `low`.

## Complexity

- **addNum:** O(log n)  
- **findMedian:** O(1)  
- **Space:** O(n)

## C++ Solution

```cpp
class MedianFinder {
    std::priority_queue<int> low; // max-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> high; // min-heap

public:
    MedianFinder() = default;

    void addNum(int num) {
        low.push(num);
        high.push(low.top());
        low.pop();
        if (low.size() < high.size()) {
            low.push(high.top());
            high.pop();
        }
    }

    double findMedian() {
        if (low.size() > high.size()) return low.top();
        return (low.top() + high.top()) / 2.0;
    }
};
```
