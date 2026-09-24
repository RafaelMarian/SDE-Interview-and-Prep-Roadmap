/*
 * Heap / priority_queue patterns for FAANG interviews
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

int findKthLargest(std::vector<int> nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minh;
    for (int x : nums) {
        minh.push(x);
        if (static_cast<int>(minh.size()) > k) minh.pop();
    }
    return minh.top();
}

std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;

    using P = std::pair<int, int>;  // freq, value
    std::priority_queue<P, std::vector<P>, std::greater<P>> minh;
    for (auto& [val, f] : freq) {
        minh.push({f, val});
        if (static_cast<int>(minh.size()) > k) minh.pop();
    }
    std::vector<int> ans;
    while (!minh.empty()) {
        ans.push_back(minh.top().second);
        minh.pop();
    }
    return ans;
}

// Merge k sorted arrays into one sorted vector
std::vector<int> mergeKSorted(const std::vector<std::vector<int>>& lists) {
    using Node = std::tuple<int, int, int>;  // value, listIdx, elemIdx
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    for (int i = 0; i < static_cast<int>(lists.size()); i++) {
        if (!lists[i].empty()) pq.push({lists[i][0], i, 0});
    }
    std::vector<int> out;
    while (!pq.empty()) {
        auto [val, li, ei] = pq.top();
        pq.pop();
        out.push_back(val);
        if (ei + 1 < static_cast<int>(lists[li].size())) {
            pq.push({lists[li][ei + 1], li, ei + 1});
        }
    }
    return out;
}

int main() {
    std::cout << findKthLargest({3, 2, 1, 5, 6, 4}, 2) << "\n";  // 5

    auto top = topKFrequent({1, 1, 1, 2, 2, 3}, 2);
    for (int x : top) std::cout << x << " ";
    std::cout << "\n";

    auto merged = mergeKSorted({{1, 4, 7}, {2, 5, 8}, {3, 6, 9}});
    for (int x : merged) std::cout << x << " ";
    std::cout << "\n";  // 1..9
    return 0;
}
