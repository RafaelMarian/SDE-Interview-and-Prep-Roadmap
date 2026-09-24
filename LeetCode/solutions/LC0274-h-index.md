# LC 274. H-Index

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Medium

## Problem
Given an array of integers `citations` where `citations[i]` is the number of citations for paper `i`, compute the h-index: the maximum value `h` such that at least `h` papers have at least `h` citations each.

## Intuition
Sort descending (or use counting). After sorting ascending, find the largest `h` where `citations[n - h] >= h`.

## Approach
1. Sort `citations` ascending.
2. For `h` from `n` down to 1, if `citations[n - h] >= h`, return `h`.
3. Return 0 if none match.

## Complexity
- Time: O(n log n)
- Space: O(1) extra excluding sort

## C++ Solution
```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = static_cast<int>(citations.size());
        for (int h = n; h >= 1; --h) {
            if (citations[n - h] >= h) {
                return h;
            }
        }
        return 0;
    }
};
```
