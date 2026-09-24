# LC 290. Word Pattern

**Lists:** Top 150
**Topic:** Hash Map
**Difficulty:** Easy

## Problem
Given pattern string `pattern` and string `s`, determine if `s` follows the same pattern. A full match means each letter in `pattern` maps to one distinct word in `s` and each word maps to one letter (bijection).

## Intuition
Split `s` into words; map pattern char ↔ word with two hash maps, rejecting inconsistent pairs.

## Approach
1. Stream words from `s`.
2. For each char in `pattern` and corresponding word, enforce `charToWord[c] == word` and `wordToChar[word] == c`.
3. After loop, word count must equal pattern length.

## Complexity
- Time: O(n)
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        unordered_map<char, string> c2w;
        unordered_map<string, char> w2c;
        string word;
        for (char c : pattern) {
            if (!(iss >> word)) {
                return false;
            }
            if (c2w.count(c) && c2w[c] != word) {
                return false;
            }
            if (w2c.count(word) && w2c[word] != c) {
                return false;
            }
            c2w[c] = word;
            w2c[word] = c;
        }
        return !(iss >> word);
    }
};
```
