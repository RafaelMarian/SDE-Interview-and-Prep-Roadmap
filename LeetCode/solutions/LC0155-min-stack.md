# LC 155. Min Stack

**Lists:** Top 150
**Topic:** Stack
**Difficulty:** Medium

## Problem
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

## Intuition
Keep a parallel stack of current minimums: on push, push `min(val, currentMin)`; on pop, pop both stacks.

## Approach
- `push(x)`: push `x` on `st`; push `min(x, minSt.back())` on `minSt` (handle empty).
- `pop`: pop both.
- `top`: return `st.top()`.
- `getMin`: return `minSt.top()`.

## Complexity
- Time: O(1) per operation
- Space: O(n)

## C++ Solution
```cpp
class MinStack {
    vector<int> st;
    vector<int> mins;

public:
    MinStack() = default;

    void push(int val) {
        st.push_back(val);
        if (mins.empty()) {
            mins.push_back(val);
        } else {
            mins.push_back(min(val, mins.back()));
        }
    }

    void pop() {
        st.pop_back();
        mins.pop_back();
    }

    int top() {
        return st.back();
    }

    int getMin() {
        return mins.back();
    }
};
```
