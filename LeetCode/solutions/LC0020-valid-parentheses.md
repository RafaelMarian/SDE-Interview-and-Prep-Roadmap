# LC 20. Valid Parentheses

**Lists:** Blind 75 · Top 150
**Topic:** Stack
**Difficulty:** Easy

## Problem
Given a string `s` containing `'('`, `')'`, `'{'`, `'}'`, `'['`, `']'`, determine if the input is valid: open brackets closed in correct order and type. Example: `s = "()[]{}"` → `true`, `s = "(]"` → `false`.

## Intuition
Each closing bracket must match the most recent unmatched opening bracket—a last-in-first-out structure. Push opens; on a close, pop and verify the pair matches.

## Approach
1. Use `stack<char>` for open brackets.
2. For each character, push if it is an opener.
3. If it is a closer and stack is empty or top mismatches, return `false`; else pop.
4. Return `true` if stack is empty at end.

## Complexity
- Time: O(n)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }
                char open = st.top();
                st.pop();
                if ((c == ')' && open != '(') ||
                    (c == '}' && open != '{') ||
                    (c == ']' && open != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
```
