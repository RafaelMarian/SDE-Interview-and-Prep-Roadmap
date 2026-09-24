# LC 6. Zigzag Conversion

**Lists:** Top 150
**Topic:** String
**Difficulty:** Medium

## Problem
Given string `s` and numRows `numRows`, arrange characters in a zigzag on the given number of rows and read line by line. Example: `s = "PAYPALISHIRING", numRows = 3` → `"PAHNAPLSIIGYIR"`.

## Intuition
Simulate rows: move down then up between row 0 and row `numRows - 1`, appending each character to its current row.

## Approach
1. If `numRows == 1` or `numRows >= s.size()`, return `s`.
2. Create `numRows` strings; track `row` and direction `down`.
3. For each char, append to `rows[row]`; flip direction at top or bottom row.
4. Concatenate all rows.

## Complexity
- Time: O(n)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= static_cast<int>(s.size())) {
            return s;
        }
        vector<string> rows(numRows);
        int row = 0, step = 1;
        for (char c : s) {
            rows[row] += c;
            if (row == 0) {
                step = 1;
            } else if (row == numRows - 1) {
                step = -1;
            }
            row += step;
        }
        string res;
        for (const string& r : rows) {
            res += r;
        }
        return res;
    }
};
```
