# 127. Word Ladder

**Lists:** Blind 75, Top Interview 150  
**Topic:** Graphs (BFS shortest path)  
**Difficulty:** Hard  

## Problem

Given two words `beginWord` and `endWord` and a dictionary `wordList`, transform `beginWord` to `endWord` by changing one letter at a time, using only words in `wordList`. Return the length of the shortest transformation sequence, or 0 if impossible.

## Intuition

Words are nodes; edges connect words differing by one letter. Shortest path in an unweighted graph is BFS level-by-level.

## Approach

1. Put all `wordList` words in a hash set.
2. BFS queue with `(word, length)` starting from `beginWord`.
3. For each word, try all 26 letters at each position; if neighbor in set, enqueue with `length + 1`. Remove visited words from set to avoid reprocessing.
4. Return length when `endWord` is reached.

## Complexity

- **Time:** O(N · L² · 26) where N is dictionary size, L word length.
- **Space:** O(N · L)

## C++ Solution

```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        dict.erase(beginWord);

        while (!q.empty()) {
            auto [word, len] = q.front();
            q.pop();
            if (word == endWord) return len;
            for (int i = 0; i < (int)word.size(); ++i) {
                char orig = word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == orig) continue;
                    word[i] = c;
                    if (dict.count(word)) {
                        if (word == endWord) return len + 1;
                        dict.erase(word);
                        q.push({word, len + 1});
                    }
                }
                word[i] = orig;
            }
        }
        return 0;
    }
};
```
