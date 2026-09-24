# 131. Palindrome Partitioning

**Lists:** Top Interview 150  
**Topic:** Backtracking  
**Difficulty:** Medium  

## Problem

Given a string `s`, partition `s` such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of `s`.

## Intuition

Try every end index for a palindrome prefix starting at `start`; recurse on the remainder. Precompute palindrome pairs with DP to test in O(1).

## Approach

1. Build `isPal[i][j]` for all substrings.
2. DFS from `start`: for `end` from `start` to n-1, if `isPal[start][end]`, push substring, recurse at `end+1`, pop.
3. When `start == n`, record path.

## Complexity

- **Time:** O(n × 2^n) worst case for generating partitions; palindrome table O(n²)
- **Space:** O(n²) for table plus recursion

## C++ Solution

```cpp
class Solution {
    vector<vector<int>> isPal;
    vector<vector<string>> result;
    vector<string> path;

    void dfs(const string& s, int start) {
        if (start == (int)s.size()) {
            result.push_back(path);
            return;
        }
        for (int end = start; end < (int)s.size(); ++end) {
            if (!isPal[start][end]) continue;
            path.push_back(s.substr(start, end - start + 1));
            dfs(s, end + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        isPal.assign(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || isPal[i + 1][j - 1]))
                    isPal[i][j] = 1;
            }
        }
        dfs(s, 0);
        return result;
    }
};
```
