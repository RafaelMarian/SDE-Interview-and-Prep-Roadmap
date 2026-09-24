# 190. Reverse Bits

**Lists:** Blind 75, Top Interview 150  
**Topic:** Bit Manipulation  
**Difficulty:** Easy  

## Problem

Reverse bits of a given 32-bit unsigned integer.

## Intuition

Pull bits from the right of input, push to the right of result.

## Approach

For 32 iterations: `result = (result << 1) | (n & 1)`, `n >>= 1`.

## Complexity

- **Time:** O(32)
- **Space:** O(1)

## C++ Solution

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
    }
};
```
