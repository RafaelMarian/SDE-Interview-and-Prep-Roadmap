# LC 30. Substring with Concatenation of All Words

**Lists:** Top 150
**Topic:** Sliding Window
**Difficulty:** Hard

## Problem
Given string `s` and an array of equal-length words `words`, find all starting indices in `s` where a substring is a concatenation of each word exactly once, in any order.

## Intuition
Word length `L` is fixed. Try each offset `0..L-1` as the start of aligned blocks; slide a window of `wordCount` blocks, maintaining counts of words seen vs required.

## Approach
1. Build frequency map of `words`; let `L = word length`, `count = words.size()`.
2. For offset `start` in `[0, L)`, reset maps and scan `i` from `start` in steps of `L`.
3. Add word at `i`; if count exceeds need, shrink from left by removing words until valid.
4. When window has exactly `count` words, record left index.

## Complexity
- Time: O(n · L) in practice O(n · wordLen) with constant alphabet
- Space: O(number of distinct words)

## C++ Solution
```cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) {
            return {};
        }
        int L = static_cast<int>(words[0].size());
        int n = static_cast<int>(s.size());
        int m = static_cast<int>(words.size());
        unordered_map<string, int> need;
        for (const string& w : words) {
            ++need[w];
        }
        vector<int> res;
        for (int start = 0; start < L; ++start) {
            unordered_map<string, int> have;
            int left = start, used = 0;
            for (int i = start; i + L <= n; i += L) {
                string w = s.substr(i, L);
                if (!need.count(w)) {
                    have.clear();
                    used = 0;
                    left = i + L;
                    continue;
                }
                ++have[w];
                ++used;
                while (have[w] > need[w]) {
                    string lw = s.substr(left, L);
                    --have[lw];
                    --used;
                    left += L;
                }
                if (used == m) {
                    res.push_back(left);
                }
            }
        }
        return res;
    }
};
```
