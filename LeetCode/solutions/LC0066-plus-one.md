# 66. Plus One

**Lists:** Top Interview 150  
**Topic:** Math  
**Difficulty:** Easy  

## Problem

You are given a large integer represented as an integer array `digits`, where each element is a digit. Increment the large integer by one and return the resulting array of digits.

## Intuition

Add 1 from the least significant digit; propagate carry while digits are 9. If all are 9, prepend 1.

## Approach

1. Scan from the last index backward.
2. If `digits[i] < 9`, increment and return.
3. Set `digits[i] = 0` and continue (carry).
4. If loop finishes, insert `1` at the front.

## Complexity

- **Time:** O(n)
- **Space:** O(1) excluding output (O(n) if new array needed for all-9 case)

## C++ Solution

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = (int)digits.size() - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```
