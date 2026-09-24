# LC 22. Generate Parentheses

**Lists:** Top 150  
**Topic:** Backtracking  
**Difficulty:** Medium

## Problem
Given `n` pairs, generate all combinations of well-formed parentheses.

Example: `n = 3` → `["((()))","(()())","(())()","()(())","()()()"]`

## Intuition
Only add `(` if open count `< n`. Only add `)` if close count `< open`. Backtrack until length `2n`.

## Approach
DFS with `(open, close)` counters and current string.

## Complexity
- Time: O(4^n / √n) (Catalan)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
    void dfs(int open, int close, int n, string& cur, vector<string>& ans) {
        if ((int)cur.size() == 2 * n) { ans.push_back(cur); return; }
        if (open < n) {
            cur.push_back('(');
            dfs(open + 1, close, n, cur, ans);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            dfs(open, close + 1, n, cur, ans);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        dfs(0, 0, n, cur, ans);
        return ans;
    }
};
```
