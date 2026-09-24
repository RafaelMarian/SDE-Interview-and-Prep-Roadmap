/*
 * Binary Search — classic, bounds, insert position, first/last, rotated array.
 * LeetCode: 704, 35, 34, 33
 */

#include <iostream>
#include <vector>
#include <algorithm>

// LeetCode 704 — classic binary search (target in sorted array)
int binarySearch(const std::vector<int>& nums, int target) {
    int lo = 0, hi = static_cast<int>(nums.size()) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// lower_bound style: first index i with nums[i] >= target (or nums.size() if none)
int lowerBound(const std::vector<int>& nums, int target) {
    int lo = 0, hi = static_cast<int>(nums.size());
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// LeetCode 35 — search insert position
int searchInsert(const std::vector<int>& nums, int target) {
    return lowerBound(nums, target);
}

// LeetCode 34 — first occurrence of target
int findFirst(const std::vector<int>& nums, int target) {
    int lo = 0, hi = static_cast<int>(nums.size());
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    if (lo == static_cast<int>(nums.size()) || nums[lo] != target) return -1;
    return lo;
}

// LeetCode 34 — last occurrence of target
int findLast(const std::vector<int>& nums, int target) {
    int lo = 0, hi = static_cast<int>(nums.size());
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    int idx = lo - 1;
    if (idx < 0 || nums[idx] != target) return -1;
    return idx;
}

// LeetCode 33 — search in rotated sorted array (no duplicates)
int searchRotated(const std::vector<int>& nums, int target) {
    int lo = 0, hi = static_cast<int>(nums.size()) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        if (nums[lo] <= nums[mid]) {
            if (nums[lo] <= target && target < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    std::vector<int> a{1, 3, 5, 5, 5, 7, 9};
    std::cout << "binarySearch(5): " << binarySearch(a, 5) << "\n";
    std::cout << "lowerBound(6): " << lowerBound(a, 6) << "\n";
    std::cout << "searchInsert(6): " << searchInsert(a, 6) << "\n";
    std::cout << "first/last 5: " << findFirst(a, 5) << ", " << findLast(a, 5) << "\n";

    std::vector<int> rot{4, 5, 6, 7, 0, 1, 2};
    std::cout << "searchRotated(0): " << searchRotated(rot, 0) << "\n";
    std::cout << "searchRotated(3): " << searchRotated(rot, 3) << "\n";
    return 0;
}
