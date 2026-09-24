# LC 202. Happy Number

**Lists:** Top 150
**Topic:** Hash Map
**Difficulty:** Easy

## Problem
Write an algorithm to determine if a number `n` is happy. Repeatedly replace `n` with the sum of squares of its digits until `n` becomes 1 (happy) or loops forever (not happy).

## Intuition
Floyd's cycle detection: slow and fast pointers on the next-digit-sum transformation detect a cycle without storing all seen values (or use a hash set of seen values).

## Approach
1. Helper `next(n)` sums squares of digits.
2. Set slow = n, fast = next(n).
3. While fast != 1 and slow != fast, advance slow once and fast twice.
4. Return `fast == 1`.

## Complexity
- Time: O(log n) iterations, digits per step O(log n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
    int nextNum(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n, fast = nextNum(n);
        while (fast != 1 && slow != fast) {
            slow = nextNum(slow);
            fast = nextNum(nextNum(fast));
        }
        return fast == 1;
    }
};
```
