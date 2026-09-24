# LC 134. Gas Station

**Lists:** Top 150
**Topic:** Array
**Difficulty:** Medium

## Problem
There are `n` gas stations in a circle. `gas[i]` is fuel at station `i`; `cost[i]` is fuel needed to reach the next station. Return the starting station index if you can complete the circuit once, otherwise `-1`. If a solution exists, it is unique.

## Intuition
If total gas ≥ total cost, some start works. Track running tank from a candidate start; if tank goes negative, no start in that segment works — reset start to next station.

## Approach
1. Sum `gas` and `cost`; if `totalGas < totalCost`, return `-1`.
2. Track `start`, `tank`; for each `i`, add `gas[i] - cost[i]` to `tank`.
3. If `tank < 0`, set `start = i + 1` and `tank = 0`.
4. Return `start`.

## Complexity
- Time: O(n)
- Space: O(1)

## C++ Solution
```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        long long total = 0, tank = 0;
        int start = 0;
        for (int i = 0; i < static_cast<int>(gas.size()); ++i) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};
```
