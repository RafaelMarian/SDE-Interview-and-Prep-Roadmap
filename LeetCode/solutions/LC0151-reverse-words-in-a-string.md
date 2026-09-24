# LC 151. Reverse Words in a String

**Lists:** Top 150
**Topic:** String
**Difficulty:** Medium

## Problem
Given a string `s`, reverse the order of words. Words are maximal non-space substrings. Return a single string with words separated by a single space and no leading or trailing spaces.

## Intuition
Split on spaces (skip empty tokens), collect words, then join in reverse order.

## Approach
1. Stream words from `s` with `istringstream`.
2. Push each word into a vector.
3. Build result: output words from last to first with single spaces between.

## Complexity
- Time: O(n)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string w;
        while (iss >> w) {
            words.push_back(w);
        }
        string res;
        for (int i = static_cast<int>(words.size()) - 1; i >= 0; --i) {
            if (!res.empty()) {
                res += ' ';
            }
            res += words[i];
        }
        return res;
    }
};
```
