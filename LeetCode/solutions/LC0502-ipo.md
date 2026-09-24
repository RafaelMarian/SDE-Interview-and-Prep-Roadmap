# 502. IPO

**Lists:** Top Interview 150  
**Topic:** Heap  
**Difficulty:** Hard  

## Problem

Suppose LeetCode starts an IPO. There are `n` projects, each with profit `profits[i]` and minimum capital `capital[i]` required to start. You start with capital `w`. You can finish at most `k` projects, earn profit after each, and use that capital for the next. Return the maximum capital after at most `k` projects.

## Intuition

Always pick the most profitable project you can afford. Projects become affordable as capital grows, so scan by increasing capital requirement while pushing newly unlocked profits into a max-heap.

## Approach

1. Pair `(capital[i], profits[i])` and sort by capital.
2. Max-heap of profits for projects with `capital <= w`.
3. Repeat up to `k` times: pop max profit from heap, add to `w`, push all projects whose capital threshold is now `<= w`.
4. Return final `w`.

## Complexity

- **Time:** O(n log n + k log n) for sorting and heap operations
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        projects.reserve(n);
        for (int i = 0; i < n; ++i) projects.emplace_back(capital[i], profits[i]);
        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfit;
        int idx = 0;
        for (int round = 0; round < k; ++round) {
            while (idx < n && projects[idx].first <= w) {
                maxProfit.push(projects[idx].second);
                ++idx;
            }
            if (maxProfit.empty()) break;
            w += maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
};
```
