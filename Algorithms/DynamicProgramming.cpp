/*
 * Dynamic Programming — classic 1D/2D patterns
 * LeetCode: 509/70, 416, 322, 1143, 300, 198
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Fibonacci / climbing stairs (LeetCode 70)
int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// 0/1 knapsack — max value with capacity W (LeetCode 416 is special case: can partition?)
int knapsack01(const std::vector<int>& wt, const std::vector<int>& val, int W) {
    int n = static_cast<int>(wt.size());
    std::vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = std::max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];
}

// Coin change — fewest coins (LeetCode 322)
int coinChange(const std::vector<int>& coins, int amount) {
    const int INF = amount + 1;
    std::vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int a = 1; a <= amount; a++) {
        for (int c : coins) {
            if (c <= a) dp[a] = std::min(dp[a], dp[a - c] + 1);
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}

// LCS length (LeetCode 1143)
int longestCommonSubsequence(const std::string& a, const std::string& b) {
    int m = static_cast<int>(a.size()), n = static_cast<int>(b.size());
    std::vector<int> prev(n + 1, 0), cur(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) cur[j] = prev[j - 1] + 1;
            else cur[j] = std::max(prev[j], cur[j - 1]);
        }
        prev.swap(cur);
    }
    return prev[n];
}

// LIS O(n^2) (LeetCode 300 — also O(n log n) with patience sorting)
int lengthOfLIS(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<int> dp(n, 1);
    int best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) dp[i] = std::max(dp[i], dp[j] + 1);
        }
        best = std::max(best, dp[i]);
    }
    return best;
}

// House robber (LeetCode 198)
int rob(const std::vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int x : nums) {
        int cur = std::max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    std::cout << "climbStairs(5): " << climbStairs(5) << "\n";

    std::vector<int> wt{1, 3, 4}, val{15, 20, 30};
    std::cout << "knapsack01 W=4: " << knapsack01(wt, val, 4) << "\n";

    std::cout << "coinChange 11 [1,2,5]: " << coinChange({1, 2, 5}, 11) << "\n";

    std::cout << "LCS abcd / ace: " << longestCommonSubsequence("abcd", "ace") << "\n";

    std::cout << "LIS: " << lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) << "\n";

    std::cout << "rob: " << rob({2, 7, 9, 3, 1}) << "\n";
    return 0;
}
