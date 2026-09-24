# LC 17. Letter Combinations of a Phone Number

**Lists:** Top 150  
**Topic:** Backtracking  
**Difficulty:** Medium

## Problem
Given a string of digits `2-9`, return all letter combinations they could represent (phone keypad).

Example: `"23"` → `["ad","ae","af","bd","be","bf","cd","ce","cf"]`

## Intuition
Each digit expands to 3–4 letters. Backtrack: append a letter for the current digit, recurse to the next digit, then undo.

## Approach
1. Map digits to strings (`2→abc`, …).  
2. DFS with index into `digits` and current path.  
3. When index == length, push path to answer.

## Complexity
- Time: O(4^n · n)
- Space: O(n) recursion (+ output)

## C++ Solution
```cpp
class Solution {
    vector<string> map_ = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(const string& digits, int i, string& path, vector<string>& ans) {
        if (i == (int)digits.size()) { ans.push_back(path); return; }
        for (char c : map_[digits[i] - '0']) {
            path.push_back(c);
            dfs(digits, i + 1, path, ans);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans;
        string path;
        dfs(digits, 0, path, ans);
        return ans;
    }
};
```
