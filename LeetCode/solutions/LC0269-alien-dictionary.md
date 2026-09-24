# 269. Alien Dictionary

**Lists:** Blind 75 (Premium)  
**Topic:** Advanced Graphs (topological sort)  
**Difficulty:** Hard  

## Problem

Given a sorted list of words in an alien language, derive the character order. Return any valid ordering, or `""` if invalid (cycle or inconsistent).

## Intuition

Adjacent words give the first differing letter `u → v` in the alien order. Build a directed graph of precedence constraints and topologically sort; cycle means no valid order.

## Approach

1. Collect all unique characters from words.
2. Compare consecutive words; detect invalid case (longer word is prefix of shorter).
3. For first mismatch `(a, b)`, add edge `a → b` (dedupe).
4. Kahn topological sort on in-degrees; if result size < number of chars, return `""`.

## Complexity

- **Time:** O(C + L) where C is total characters, L comparisons of word pairs.
- **Space:** O(1) alphabet (26) for graph.

## C++ Solution

```cpp
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indeg;
        for (const string& w : words)
            for (char c : w) indeg[c] = 0;

        for (int i = 0; i + 1 < (int)words.size(); ++i) {
            const string& w1 = words[i], &w2 = words[i + 1];
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) return "";
            for (int j = 0; j < (int)min(w1.size(), w2.size()); ++j) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        ++indeg[w2[j]];
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for (auto& [c, d] : indeg)
            if (d == 0) q.push(c);

        string order;
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            order.push_back(c);
            for (char nxt : adj[c])
                if (--indeg[nxt] == 0) q.push(nxt);
        }
        return order.size() == indeg.size() ? order : "";
    }
};
```
