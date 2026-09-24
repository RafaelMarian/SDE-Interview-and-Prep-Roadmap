/*
 * Greedy patterns for FAANG interviews
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

bool canJump(const std::vector<int>& a) {
    int far = 0;
    for (int i = 0; i < static_cast<int>(a.size()); i++) {
        if (i > far) return false;
        far = std::max(far, i + a[i]);
    }
    return true;
}

int jump(const std::vector<int>& a) {
    int jumps = 0, curEnd = 0, far = 0;
    for (int i = 0; i < static_cast<int>(a.size()) - 1; i++) {
        far = std::max(far, i + a[i]);
        if (i == curEnd) {
            jumps++;
            curEnd = far;
        }
    }
    return jumps;
}

int eraseOverlapIntervals(std::vector<std::vector<int>> intervals) {
    if (intervals.empty()) return 0;
    std::sort(intervals.begin(), intervals.end(),
              [](const auto& x, const auto& y) { return x[1] < y[1]; });
    int keep = 1, end = intervals[0][1];
    for (int i = 1; i < static_cast<int>(intervals.size()); i++) {
        if (intervals[i][0] >= end) {
            keep++;
            end = intervals[i][1];
        }
    }
    return static_cast<int>(intervals.size()) - keep;
}

// Meeting rooms II — min rooms = max concurrent
int minMeetingRooms(std::vector<std::vector<int>> intervals) {
    std::sort(intervals.begin(), intervals.end());
    std::priority_queue<int, std::vector<int>, std::greater<int>> ends;
    for (auto& it : intervals) {
        if (!ends.empty() && ends.top() <= it[0]) ends.pop();
        ends.push(it[1]);
    }
    return static_cast<int>(ends.size());
}

// Fractional knapsack — max value with capacity W
double fractionalKnapsack(std::vector<int> wt, std::vector<int> val, int W) {
    int n = static_cast<int>(wt.size());
    std::vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = i;
    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
        return (double)val[i] / wt[i] > (double)val[j] / wt[j];
    });
    double ans = 0;
    for (int i : idx) {
        if (W >= wt[i]) {
            W -= wt[i];
            ans += val[i];
        } else {
            ans += (double)val[i] * W / wt[i];
            break;
        }
    }
    return ans;
}

int main() {
    std::cout << std::boolalpha << canJump({2, 3, 1, 1, 4}) << "\n";  // true
    std::cout << jump({2, 3, 1, 1, 4}) << "\n";                       // 2
    std::cout << eraseOverlapIntervals({{1, 2}, {2, 3}, {3, 4}, {1, 3}}) << "\n";  // 1
    std::cout << minMeetingRooms({{0, 30}, {5, 10}, {15, 20}}) << "\n";  // 2
    std::cout << fractionalKnapsack({10, 20, 30}, {60, 100, 120}, 50) << "\n";  // 240
    return 0;
}
