# 50. Pow(x, n)

**Lists:** Top Interview 150  
**Topic:** Math  
**Difficulty:** Medium  

## Problem

Implement `pow(x, n)`, which calculates `x` raised to the power `n` (i.e., x^n).

## Intuition

Binary exponentiation: x^n = (x^(n/2))² when n is even; when n is odd, multiply by one extra x. Handle negative n with 1/x.

## Approach

1. Use `long long exp = n`; if `n < 0`, `x = 1/x`, `exp = -exp`.
2. While `exp > 0`: if `exp` is odd, `ans *= x`; `x *= x`; `exp /= 2`.
3. Return `ans`.

## Complexity

- **Time:** O(log |n|)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }
        double ans = 1.0;
        while (exp > 0) {
            if (exp & 1) ans *= x;
            x *= x;
            exp >>= 1;
        }
        return ans;
    }
};
```
