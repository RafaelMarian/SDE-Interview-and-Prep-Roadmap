/*
 * Dynamic Programming patterns for FAANG interviews
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

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

int rob(const std::vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int x : nums) {
        int cur = std::max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int coinChange(const std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int a = 1; a <= amount; a++) {
        for (int c : coins) {
            if (c <= a) dp[a] = std::min(dp[a], dp[a - c] + 1);
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int lengthOfLIS(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<int> dp(n, 1);
    int best = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) dp[i] = std::max(dp[i], dp[j] + 1);
        }
        best = std::max(best, dp[i]);
    }
    return best;
}

int longestCommonSubsequence(const std::string& a, const std::string& b) {
    int n = static_cast<int>(a.size()), m = static_cast<int>(b.size());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

// 0/1 knapsack: max value with capacity W
int knapsack(const std::vector<int>& wt, const std::vector<int>& val, int W) {
    int n = static_cast<int>(wt.size());
    std::vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = std::max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];
}

int main() {
    std::cout << climbStairs(5) << "\n";                 // 8
    std::cout << rob({2, 7, 9, 3, 1}) << "\n";            // 12
    std::cout << coinChange({1, 2, 5}, 11) << "\n";       // 3
    std::cout << lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) << "\n";  // 4
    std::cout << longestCommonSubsequence("abcde", "ace") << "\n";   // 3
    std::cout << knapsack({1, 3, 4}, {15, 20, 30}, 4) << "\n";        // 35? wait 1+3 -> 35
    return 0;
}
