/*
 * Hash map / set patterns for FAANG interviews
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen;
    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        int need = target - nums[i];
        if (seen.count(need)) return {seen[need], i};
        seen[nums[i]] = i;
    }
    return {};
}

std::vector<std::vector<std::string>> groupAnagrams(
    const std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (const auto& s : strs) {
        std::string key = s;
        std::sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    std::vector<std::vector<std::string>> ans;
    for (auto& [_, g] : groups) ans.push_back(std::move(g));
    return ans;
}

int longestConsecutive(std::vector<int> nums) {
    std::unordered_set<int> s(nums.begin(), nums.end());
    int best = 0;
    for (int x : s) {
        if (s.count(x - 1)) continue;  // only start of a streak
        int len = 1;
        while (s.count(x + len)) len++;
        best = std::max(best, len);
    }
    return best;
}

int subarraySum(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq{{0, 1}};
    int sum = 0, ans = 0;
    for (int x : nums) {
        sum += x;
        ans += freq[sum - k];
        freq[sum]++;
    }
    return ans;
}

int main() {
    auto p = twoSum({2, 7, 11, 15}, 9);
    std::cout << p[0] << " " << p[1] << "\n";  // 0 1

    auto groups = groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"});
    std::cout << groups.size() << "\n";  // 3

    std::cout << longestConsecutive({100, 4, 200, 1, 3, 2}) << "\n";  // 4
    std::cout << subarraySum({1, 1, 1}, 2) << "\n";  // 2
    return 0;
}
