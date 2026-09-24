/*
 * Stack patterns for FAANG interviews (C++)
 * - Valid parentheses
 * - Next greater element (monotonic stack)
 * - Min stack
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <climits>

bool isValid(const std::string& s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char t = st.top();
            st.pop();
            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}

std::vector<int> nextGreaterElements(const std::vector<int>& a) {
    int n = static_cast<int>(a.size());
    std::vector<int> ans(n, -1);
    std::stack<int> st;  // indices, values decreasing from bottom to top
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) {
            ans[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

class MinStack {
    std::stack<int> vals;
    std::stack<int> mins;
public:
    void push(int x) {
        vals.push(x);
        if (mins.empty() || x <= mins.top()) mins.push(x);
        else mins.push(mins.top());
    }
    void pop() {
        vals.pop();
        mins.pop();
    }
    int top() const { return vals.top(); }
    int getMin() const { return mins.top(); }
};

int main() {
    std::cout << std::boolalpha;
    std::cout << isValid("()[]{}") << "\n";   // true
    std::cout << isValid("(]") << "\n";       // false

    auto ng = nextGreaterElements({2, 1, 2, 4, 3});
    for (int x : ng) std::cout << x << " ";   // 4 2 4 -1 -1
    std::cout << "\n";

    MinStack ms;
    ms.push(3);
    ms.push(1);
    ms.push(2);
    std::cout << ms.getMin() << "\n";  // 1
    ms.pop();
    std::cout << ms.getMin() << "\n";  // 1
    ms.pop();
    std::cout << ms.getMin() << "\n";  // 3
    return 0;
}
