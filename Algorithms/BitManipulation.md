# Bit Manipulation

Use individual bits for compact state, O(1) set ops, and xor-based parity tricks. Common in FAANG phone screens and system design follow-ups.

## Core operations

```cpp
// i-th bit (0 = LSB)
bool get  = (x >> i) & 1;
int  set  = x | (1 << i);
int  clr  = x & ~(1 << i);
int  flip = x ^ (1 << i);

// count set bits
int c = __builtin_popcount((unsigned)x);   // GCC/Clang
// C++20: std::popcount((unsigned)x);
```

## When to use

- **Single / missing number** — xor cancels pairs.
- **Power of two** — `n & (n-1)` clears lowest set bit.
- **Subsets of small n** — iterate `mask` from `0` to `(1<<n)-1`.
- **Flags / permissions** — bitmask in one `int`.

## Key identities

| Idea | Expression |
|------|------------|
| Isolate lowest set bit | `x & -x` |
| Clear lowest set bit | `x & (x - 1)` |
| Power of 2 | `n > 0 && (n & (n-1)) == 0` |
| Swap without temp | `a^=b; b^=a; a^=b` (integers only) |

## Subset enumeration (n ≤ 20)

```cpp
for (int mask = 0; mask < (1 << n); mask++)
    for (int i = 0; i < n; i++)
        if (mask & (1 << i)) /* include i */;
```

## Pitfalls

- Shift amount ≥ bit width → undefined behavior; guard `i < 31` for `int`.
- Signed vs unsigned: prefer `unsigned` for popcount and shifts.
- `1 << i` overflows if `i == 31` on 32-bit `int` — use `1LL << i` when needed.

## Practice

| # | Problem | Trick |
|---|---------|-------|
| 136 | Single Number | xor all |
| 137 | Single Number II | bit count mod 3 |
| 191 | Number of 1 Bits | `n &= n-1` |
| 231 | Power of Two | `n & (n-1)` |
| 338 | Counting Bits | DP on bits |
| 78 | Subsets | bitmask alternative |
| 421 | Max XOR of Two Numbers | trie / sort |
