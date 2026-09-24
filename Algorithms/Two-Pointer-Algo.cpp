/*
 * Example 1: Given a string s, return true if it is a palindrome, false otherwise.
 *
 * A string is a palindrome if it reads the same forward as backward. That means,
 * after reversing it, it is still the same string. For example: "abcdcba", or "racecar".
 */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

bool palindrome(const std::string& s) {
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

/*
 * 125. Valid Palindrome - https://leetcode.com/problems/valid-palindrome/description/
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase
 * letters and removing all non-alphanumeric characters, it reads the same forward
 * and backward. Alphanumeric characters include letters and numbers.
 *
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 *
 * Input: s = "race a car"
 * Output: false
 *
 * Input: s = " "
 * Output: true
 */

bool isPalindrome(std::string s) {
    std::string cleaned;
    cleaned.reserve(s.size());
    for (char c : s) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            cleaned.push_back(static_cast<char>(
                std::tolower(static_cast<unsigned char>(c))));
        }
    }

    int left = 0;
    int right = static_cast<int>(cleaned.size()) - 1;
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

/*
 * 1. Two Sum - https://leetcode.com/problems/two-sum/description/ but SORTED
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * You can return the answer in any order.
 */

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {left, right};
        } else if (sum > target) {
            right--;
        } else {
            left++;
        }
    }
    return {-1, -1};
}

/*
 * Example: Given two sorted integer arrays arr1 and arr2, return a new array
 * that combines both of them and is also sorted.
 */

std::vector<int> mergedSorted(const std::vector<int>& arr1,
                              const std::vector<int>& arr2) {
    size_t i = 0, j = 0;
    std::vector<int> result;
    result.reserve(arr1.size() + arr2.size());

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        result.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        result.push_back(arr2[j]);
        j++;
    }

    return result;
}

int main() {
    auto merged = mergedSorted({1, 2, 5, 6}, {4, 5, 7, 8});
    for (size_t i = 0; i < merged.size(); i++) {
        if (i) std::cout << " ";
        std::cout << merged[i];
    }
    std::cout << "\n";  // Output: 1 2 4 5 5 6 7 8

    std::cout << std::boolalpha;
    std::cout << palindrome("racecar") << "\n";           // true
    std::cout << isPalindrome("A man, a plan, a canal: Panama") << "\n";  // true

    auto pair = twoSum({1, 2, 3, 4, 6}, 10);
    std::cout << pair[0] << " " << pair[1] << "\n";  // 3 4 (4 + 6)

    return 0;
}
