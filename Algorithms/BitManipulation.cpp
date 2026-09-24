/*
 * Bit manipulation patterns for FAANG interviews
 */

#include <iostream>
#include <vector>
#include <cstdint>

bool getBit(int x, int i) { return (x & (1 << i)) != 0; }
int setBit(int x, int i) { return x | (1 << i); }
int clearBit(int x, int i) { return x & ~(1 << i); }

int hammingWeight(uint32_t n) {
    int c = 0;
    while (n) {
        n &= n - 1;
        c++;
    }
    return c;
}

int singleNumber(const std::vector<int>& nums) {
    int x = 0;
    for (int v : nums) x ^= v;
    return x;
}

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

std::vector<std::vector<int>> subsetsBitmask(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<std::vector<int>> ans;
    for (int mask = 0; mask < (1 << n); mask++) {
        std::vector<int> cur;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) cur.push_back(nums[i]);
        ans.push_back(cur);
    }
    return ans;
}

std::vector<int> countBits(int n) {
    std::vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) dp[i] = dp[i >> 1] + (i & 1);
    return dp;
}

int main() {
    std::cout << getBit(0b1010, 1) << "\n";           // 1
    std::cout << setBit(0b1000, 0) << "\n";           // 9
    std::cout << clearBit(0b1111, 0) << "\n";         // 14
    std::cout << hammingWeight(0b00000000000000000000000000001011) << "\n";  // 3
    std::cout << singleNumber({4, 1, 2, 1, 2}) << "\n";  // 4
    std::cout << std::boolalpha << isPowerOfTwo(16) << " " << isPowerOfTwo(3) << "\n";
    std::cout << subsetsBitmask({1, 2, 3}).size() << "\n";  // 8
    auto cb = countBits(2);
    for (int x : cb) std::cout << x << " ";  // 0 1 1
    std::cout << "\n";
    return 0;
}
