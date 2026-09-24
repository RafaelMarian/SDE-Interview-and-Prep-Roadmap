/*
 * Bit manipulation — basics, xor tricks, power of two, subset bitmask
 */

#include <iostream>
#include <vector>
#include <iomanip>

bool getBit(int x, int i) { return (x >> i) & 1; }

int setBit(int x, int i) { return x | (1 << i); }

int clearBit(int x, int i) { return x & ~(1 << i); }

int popCount(unsigned x) {
    return __builtin_popcount(x);
}

// LeetCode 136 — single number (every element twice except one)
int singleNumber(const std::vector<int>& nums) {
    int x = 0;
    for (int v : nums) x ^= v;
    return x;
}

// LeetCode 231 — power of two
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// All subsets of {0..n-1} for small n (n <= 20 typical)
std::vector<std::vector<int>> subsetsBitmask(int n) {
    std::vector<std::vector<int>> res;
    int total = 1 << n;
    for (int mask = 0; mask < total; mask++) {
        std::vector<int> sub;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sub.push_back(i);
        }
        res.push_back(std::move(sub));
    }
    return res;
}

int main() {
    int x = 0b1010;
    std::cout << "getBit(1): " << getBit(x, 1) << "\n";
    std::cout << "setBit(2): " << std::setbase(2) << setBit(x, 2) << std::dec << "\n";
    std::cout << "clearBit(1): " << std::setbase(2) << clearBit(x, 1) << std::dec << "\n";
    std::cout << "popCount: " << popCount(0b101101) << "\n";

    std::cout << "singleNumber: " << singleNumber({4, 1, 2, 1, 2}) << "\n";
    std::cout << "isPowerOfTwo(16): " << isPowerOfTwo(16) << "\n";
    std::cout << "isPowerOfTwo(18): " << isPowerOfTwo(18) << "\n";

    auto subs = subsetsBitmask(3);
    std::cout << "subsetsBitmask n=3 count: " << subs.size() << "\n";
    return 0;
}
