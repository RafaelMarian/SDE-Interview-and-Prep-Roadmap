# 69. Sqrt(x)

**Lists:** Top Interview 150  
**Topic:** Math  
**Difficulty:** Easy  

## Problem

Given a non-negative integer `x`, return the square root of `x` rounded down to the nearest integer. The returned integer must be non-negative as well.

## Intuition

Binary search on the answer in `[0, x]`: mid is a candidate root if `mid * mid <= x` and `(mid+1) * (mid+1) > x`.

## Approach

1. Handle `x < 2` → return `x`.
2. Binary search `lo = 2`, `hi = x/2`.
3. While `lo <= hi`, if `mid * mid <= x`, record `ans = mid`, search right; else search left.
4. Return `ans`.

## Complexity

- **Time:** O(log x)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int lo = 2, hi = x / 2, ans = 1;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (mid * mid <= x) {
                ans = (int)mid;
                lo = (int)mid + 1;
            } else {
                hi = (int)mid - 1;
            }
        }
        return ans;
    }
};
```
