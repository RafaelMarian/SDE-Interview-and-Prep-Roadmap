# LC 150. Evaluate Reverse Polish Notation

**Lists:** Top 150
**Topic:** Stack
**Difficulty:** Medium

## Problem
Evaluate an arithmetic expression in Reverse Polish Notation. Valid operators are `+`, `-`, `*`, `/`. Division truncates toward zero. Each operand may be an integer or an operator with two operands.

## Intuition
Use a stack: push numbers; on operator, pop two operands, apply operator, push result.

## Approach
1. For each token, if it is an operator, pop `b` then `a`, push `a op b`.
2. Otherwise push `stoi(token)`.
3. Return the single value left on the stack.

## Complexity
- Time: O(n)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<long long> st;
        for (const string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                long long b = st.back(); st.pop_back();
                long long a = st.back(); st.pop_back();
                if (t == "+") {
                    st.push_back(a + b);
                } else if (t == "-") {
                    st.push_back(a - b);
                } else if (t == "*") {
                    st.push_back(a * b);
                } else {
                    st.push_back(a / b);
                }
            } else {
                st.push_back(stoll(t));
            }
        }
        return static_cast<int>(st.back());
    }
};
```
