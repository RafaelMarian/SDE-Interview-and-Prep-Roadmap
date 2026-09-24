# LC 13. Roman to Integer

**Lists:** Top 150
**Topic:** String
**Difficulty:** Easy

## Problem
Given a Roman numeral string `s`, convert it to an integer. Subtractive pairs like `IV` (4) and `IX` (9) use a smaller symbol before a larger one.

## Intuition
Usually add symbol values left to right; if a symbol is less than the next, subtract it instead of adding.

## Approach
1. Map each char to its value.
2. Scan `s`; add `val[i]`, but if `val[i] < val[i + 1]`, subtract `val[i]` instead.
3. Return the sum.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            if (i + 1 < static_cast<int>(s.size()) && val[s[i]] < val[s[i + 1]]) {
                sum -= val[s[i]];
            } else {
                sum += val[s[i]];
            }
        }
        return sum;
    }
};
```
