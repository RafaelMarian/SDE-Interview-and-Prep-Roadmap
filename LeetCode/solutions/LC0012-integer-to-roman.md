# LC 12. Integer to Roman

**Lists:** Top 150
**Topic:** String
**Difficulty:** Medium

## Problem
Given an integer `num` in the range `[1, 3999]`, convert it to a Roman numeral string.

## Intuition
Greedy subtraction from largest value symbols, including subtractive pairs (900, 400, 90, 40, 9, 4) encoded as pairs in a table.

## Approach
1. Use arrays of values and corresponding numeral strings in descending order (include subtractive forms).
2. While `num > 0`, repeatedly append the symbol for the largest value ≤ `num` and subtract.
3. Return the built string.

## Complexity
- Time: O(1) — fixed numeral set
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<int, string>> pairs = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string res;
        for (const auto& [v, sym] : pairs) {
            while (num >= v) {
                res += sym;
                num -= v;
            }
        }
        return res;
    }
};
```
