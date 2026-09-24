/*
 * Binary search patterns for FAANG interviews
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int binarySearch(const std::vector<int>& a, int target) {
    int lo = 0, hi = static_cast<int>(a.size()) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int lowerBoundIdx(const std::vector<int>& a, int target) {
    int lo = 0, hi = static_cast<int>(a.size());
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

std::vector<int> searchRange(const std::vector<int>& a, int target) {
    auto lb = std::lower_bound(a.begin(), a.end(), target);
    if (lb == a.end() || *lb != target) return {-1, -1};
    auto ub = std::upper_bound(a.begin(), a.end(), target);
    return {static_cast<int>(lb - a.begin()),
            static_cast<int>(ub - a.begin()) - 1};
}

int searchRotated(const std::vector<int>& a, int target) {
    int lo = 0, hi = static_cast<int>(a.size()) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[lo] <= a[mid]) {  // left half sorted
            if (a[lo] <= target && target < a[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else {  // right half sorted
            if (a[mid] < target && target <= a[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

// Binary search on answer: min speed to eat all bananas in h hours
bool canEat(const std::vector<int>& piles, int h, int speed) {
    long long hours = 0;
    for (int p : piles) hours += (p + speed - 1LL) / speed;
    return hours <= h;
}

int minEatingSpeed(const std::vector<int>& piles, int h) {
    int lo = 1, hi = *std::max_element(piles.begin(), piles.end());
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (canEat(piles, h, mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    std::vector<int> a = {1, 2, 2, 2, 3, 5};
    std::cout << binarySearch(a, 3) << "\n";           // 4
    std::cout << lowerBoundIdx(a, 2) << "\n";          // 1
    auto rg = searchRange(a, 2);
    std::cout << rg[0] << " " << rg[1] << "\n";        // 1 3
    std::cout << searchRotated({4, 5, 6, 7, 0, 1, 2}, 0) << "\n";  // 4
    std::cout << minEatingSpeed({3, 6, 7, 11}, 8) << "\n";         // 4
    return 0;
}
