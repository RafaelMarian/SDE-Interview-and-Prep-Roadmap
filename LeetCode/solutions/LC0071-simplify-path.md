# LC 71. Simplify Path

**Lists:** Top 150
**Topic:** Stack
**Difficulty:** Medium

## Problem
Given an absolute Unix-style path `path`, convert it to its simplified canonical path: single slashes, `.` ignored, `..` pops parent, no trailing slash except root.

## Intuition
Split on `/` and simulate a stack of directory names; push valid names, pop on `..`, ignore `.` and empty tokens.

## Approach
1. Stream tokens separated by `/`.
2. On name: push to stack unless `..` (pop if non-empty) or `.` or empty.
3. Join stack with `/` prefixed by `/`; empty stack → `"/"`.

## Complexity
- Time: O(n)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        istringstream iss(path);
        string token;
        while (getline(iss, token, '/')) {
            if (token.empty() || token == ".") {
                continue;
            }
            if (token == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            } else {
                stk.push_back(token);
            }
        }
        if (stk.empty()) {
            return "/";
        }
        string res;
        for (const string& s : stk) {
            res += "/" + s;
        }
        return res;
    }
};
```
