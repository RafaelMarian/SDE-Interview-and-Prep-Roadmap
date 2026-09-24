# LC 135. Candy

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Hard

## Problem
`n` children stand in a line with ratings `ratings[i]`. Give each child at least one candy; higher-rated children get more than immediate neighbors. Return the minimum total candies.

## Intuition
Two passes enforce left and right constraints: left-to-right ensures right neighbor gets more candy when rating increases; right-to-left enforces the same from the other side. Take the max at each index.

## Approach
1. Initialize `candies` to all 1s.
2. Left-to-right: if `ratings[i] > ratings[i - 1]`, set `candies[i] = candies[i - 1] + 1`.
3. Right-to-left: if `ratings[i] > ratings[i + 1]`, set `candies[i] = max(candies[i], candies[i + 1] + 1)`.
4. Sum `candies`.

## Complexity
- Time: O(n)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = static_cast<int>(ratings.size());
        vector<int> candies(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
```
