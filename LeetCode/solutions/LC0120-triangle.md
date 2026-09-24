# 120. Triangle

**Lists:** Top Interview 150  
**Topic:** 1D DP  
**Difficulty:** Medium  

## Problem

Given a triangle array `triangle`, return the minimum path sum from top to bottom. Each step may move to the adjacent number below or to the number below-right.

## Intuition

Classic bottom-up DP: minimum cost to reach row `i` from the bottom is the triangle value plus the min of the two cells below in the next row.

## Approach

1. Copy last row into `dp` or use the triangle bottom row.
2. From second-to-last row upward: `dp[j] = triangle[i][j] + min(dp[j], dp[j+1])`.
3. Return `dp[0]`.

## Complexity

- **Time:** O(n²) for n rows
- **Space:** O(n)

## C++ Solution

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp = triangle.back();
        for (int i = (int)triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j)
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        }
        return dp[0];
    }
};
```
