# LC 238. Product of Array Except Self

**Lists:** Blind 75 · Top 150
**Topic:** Arrays & Hashing
**Difficulty:** Medium

## Problem
Given an integer array `nums`, return an array `answer` where `answer[i]` is the product of all elements of `nums` except `nums[i]`. You must run in O(n) time without using division. Example: `nums = [1,2,3,4]` → `[24,12,8,6]`.

## Intuition
`answer[i]` equals the product of everything to the left times everything to the right. One pass can fill prefix products; a second pass from the right multiplies in suffix products using a running variable.

## Approach
1. Initialize `answer` with `1`s.
2. Left-to-right: multiply each `answer[i]` by running product of elements before `i`.
3. Right-to-left: multiply each `answer[i]` by running product of elements after `i`.
4. Return `answer`.

## Complexity
- Time: O(n)
- Space: O(1) extra excluding output

## C++ Solution
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> answer(n, 1);
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        return answer;
    }
};
```
