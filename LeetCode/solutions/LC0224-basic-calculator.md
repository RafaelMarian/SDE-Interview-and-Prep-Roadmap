# LC 224. Basic Calculator

**Lists:** Top 150
**Topic:** Stack
**Difficulty:** Hard

## Problem
Given string `s` representing a valid expression with digits, `+`, `-`, parentheses, and spaces, evaluate the integer result.

## Intuition
Track current number, sign, and running result. On `(`, push result and sign onto a stack; on `)`, combine with stacked state. Handle unary minus by treating sign flips when seeing `(` after `-` or at expression start.

## Approach
1. Maintain `res`, `sign`, `num`, and stack of `{prevRes, prevSign}`.
2. Scan chars: build multi-digit numbers; on `+`/`-` finalize term; on `(` push state and reset; on `)` pop and merge.
3. After loop, add last signed number to `res`.

## Complexity
- Time: O(n)
- Space: O(n) for stack depth

## C++ Solution
```cpp
class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, num = 0;
        stack<int> signs;
        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                signs.push(res);
                signs.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                int prevSign = signs.top(); signs.pop();
                int prevRes = signs.top(); signs.pop();
                res = prevRes + prevSign * res;
            }
        }
        res += sign * num;
        return res;
    }
};
```
