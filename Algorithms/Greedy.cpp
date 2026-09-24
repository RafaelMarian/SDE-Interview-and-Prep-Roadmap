/*
 * Greedy — jump game, activity selection, gas station, fractional knapsack
 * LeetCode: 55, 435/252, 134, classic fractional knapsack
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// LeetCode 55 — jump game (can reach last index?)
bool canJump(const std::vector<int>& nums) {
    int reach = 0;
    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        if (i > reach) return false;
        reach = std::max(reach, i + nums[i]);
        if (reach >= static_cast<int>(nums.size()) - 1) return true;
    }
    return true;
}

struct Interval {
    int start, end;
};

// Activity selection — max non-overlapping intervals (LeetCode 435 style)
int maxNonOverlapping(std::vector<Interval> intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const Interval& a, const Interval& b) { return a.end < b.end; });
    int count = 0, lastEnd = INT_MIN;
    for (const auto& iv : intervals) {
        if (iv.start >= lastEnd) {
            count++;
            lastEnd = iv.end;
        }
    }
    return count;
}

// LeetCode 134 — gas station circuit
int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < static_cast<int>(gas.size()); i++) {
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

struct Item {
    int weight;
    double value;
};

// Fractional knapsack — take fractions by value/weight ratio
double fractionalKnapsack(int capacity, std::vector<Item> items) {
    std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return (a.value / a.weight) > (b.value / b.weight);
    });
    double total = 0.0;
    for (const auto& it : items) {
        if (capacity <= 0) break;
        int take = std::min(capacity, it.weight);
        total += (static_cast<double>(take) / it.weight) * it.value;
        capacity -= take;
    }
    return total;
}

int main() {
    std::cout << "canJump: " << (canJump({2, 3, 1, 1, 4}) ? "true" : "false") << "\n";

    std::vector<Interval> meetings{{1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}};
    std::cout << "maxNonOverlapping: " << maxNonOverlapping(meetings) << "\n";

    std::vector<int> gas{1, 2, 3, 4, 5}, cost{3, 4, 5, 1, 2};
    std::cout << "gas station start: " << canCompleteCircuit(gas, cost) << "\n";

    std::vector<Item> items{{10, 60}, {20, 100}, {30, 120}};
    std::cout << "fractional knapsack W=50: " << fractionalKnapsack(50, items) << "\n";
    return 0;
}
