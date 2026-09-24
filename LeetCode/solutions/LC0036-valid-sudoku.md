# LC 36. Valid Sudoku

**Lists:** Top 150
**Topic:** Hash Map
**Difficulty:** Medium

## Problem
Determine if a 9×9 Sudoku board is valid: each row, column, and 3×3 sub-box contains digits `1-9` at most once. Empty cells are `'.'`.

## Intuition
Track seen digits per row, column, and box using bitmasks or hash sets in one pass.

## Approach
1. Arrays `rows[9]`, `cols[9]`, `boxes[9]` as bitmasks (or bool[9][9]).
2. For each cell with digit `d`, compute box index `(r/3)*3 + c/3`.
3. If bit already set in row/col/box, return false; else set bits.
4. Return true if no conflict.

## Complexity
- Time: O(81) = O(1)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<int, 9> rows{}, cols{}, boxes{};
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') {
                    continue;
                }
                int bit = 1 << (ch - '1');
                int b = (r / 3) * 3 + c / 3;
                if ((rows[r] & bit) || (cols[c] & bit) || (boxes[b] & bit)) {
                    return false;
                }
                rows[r] |= bit;
                cols[c] |= bit;
                boxes[b] |= bit;
            }
        }
        return true;
    }
};
```
