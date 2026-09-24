# Bit Manipulation

Operate on binary representation. Useful for flags, subsets, and XOR tricks.

## Essentials

```cpp
x & 1          // odd?
x & (1 << i)   // test bit i
x | (1 << i)   // set bit i
x & ~(1 << i)  // clear bit i
x ^ (1 << i)   // toggle bit i
x & -x         // lowest set bit (2's complement)
x & (x - 1)    // clear lowest set bit
__builtin_popcount(x)  // count bits (GCC/Clang)
```

## Classic tricks

| Trick | Idea |
|-------|------|
| Single number | XOR all — duplicates cancel |
| Power of two | `n > 0 && (n & (n-1)) == 0` |
| Subsets of n | iterate mask `0 .. (1<<n)-1` |
| Swap | `a ^= b; b ^= a; a ^= b;` |

## Practice
| # | Problem |
|---|---------|
| LC 136 | Single Number |
| LC 191 | Number of 1 Bits |
| LC 231 | Power of Two |
| LC 338 | Counting Bits |
| LC 78 | Subsets (bitmask version) |

See [`BitManipulation.cpp`](./BitManipulation.cpp).
