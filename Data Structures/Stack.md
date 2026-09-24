# Stack

LIFO container. In C++ interviews: `std::stack` or just a `std::vector` used as a stack (`push_back` / `pop_back`).

## When it shows up

- Matching parentheses / valid path strings
- Monotonic stack (next greater/smaller element)
- Evaluate RPN / calculator
- DFS iterative, undo history
- Histogram largest rectangle, daily temperatures

## Core API

```cpp
std::stack<int> st;
st.push(x);
st.top();
st.pop();
st.empty();
st.size();
```

Prefer `vector` when you need random access to the underlying sequence.

## Patterns

### 1. Valid parentheses
Push opening brackets; on closing, check top matches.

### 2. Monotonic stack
Maintain increasing/decreasing values to answer “next greater” in O(n):

```cpp
vector<int> nextGreater(const vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st; // indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) {
            ans[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
```

## Complexity
Push/pop/top: **O(1)**. Monotonic stack over array: **O(n)** time, **O(n)** space.

## Practice
| # | Problem |
|---|---------|
| LC 20 | Valid Parentheses |
| LC 155 | Min Stack |
| LC 739 | Daily Temperatures |
| LC 84 | Largest Rectangle in Histogram |
| LC 150 | Evaluate Reverse Polish Notation |

See [`Stack.cpp`](./Stack.cpp).
