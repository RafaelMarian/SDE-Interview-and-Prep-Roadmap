# 140. Word Break II

**Lists:** Top Interview 150  
**Topic:** 1D DP / Backtracking  
**Difficulty:** Hard  

## Problem

Given a string `s` and a dictionary of strings `wordDict`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Return all such sentences in any order. It is guaranteed that the same word may be reused multiple times.

## Intuition

First verify reachability with standard Word Break DP. Then DFS from index 0: try each dictionary word that matches a prefix and recurse on the suffix, memoizing concatenations from each start index.

## Approach

1. Build `wordSet` and `dpReach[i]` = whether `s[i..]` can be segmented (bottom-up from end).
2. If not `dpReach[0]`, return `{}`.
3. `dfs(pos)`: for each word in dict matching at `pos`, if remainder segmentable, append `word + " " + rest` from memoized `dfs(nextPos)`.
4. Memoize lists per starting index.

## Complexity

- **Time:** O(n² + outputs) in practice; dictionary scan can be optimized with trie
- **Space:** O(n + total output size)

## C++ Solution

```cpp
class Solution {
    unordered_set<string> dict;
    vector<int> reachable;
    unordered_map<int, vector<string>> memo;
    string s;

    vector<string> dfs(int start) {
        if (start == (int)s.size()) return {""};
        if (memo.count(start)) return memo[start];
        vector<string> res;
        for (int end = start + 1; end <= (int)s.size(); ++end) {
            if (!reachable[end]) continue;
            string word = s.substr(start, end - start);
            if (!dict.count(word)) continue;
            for (const string& tail : dfs(end)) {
                res.push_back(tail.empty() ? word : word + " " + tail);
            }
        }
        return memo[start] = move(res);
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = move(s);
        dict.insert(wordDict.begin(), wordDict.end());
        int n = this->s.size();
        reachable.assign(n + 1, 0);
        reachable[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j <= n; ++j) {
                if (!reachable[j]) continue;
                if (dict.count(this->s.substr(i, j - i))) {
                    reachable[i] = 1;
                    break;
                }
            }
        }
        if (!reachable[0]) return {};
        return dfs(0);
    }
};
```
