# LC 433. Minimum Genetic Mutation

**Lists:** Top 150  
**Topic:** Graph BFS  
**Difficulty:** Medium

## Problem
From `startGene` to `endGene` mutating one char at a time among `ACGT`, only through `bank`. Return min mutations or −1.

## Intuition
Word Ladder variant: BFS where each gene is a node; edges = one-char difference in bank.

## Approach
1. Put bank in a set.  
2. BFS from start; for each gene try all one-char mutations.  
3. First time reaching end → steps.

## Complexity
- Time: O(B · L · 4 · L) roughly
- Space: O(B)

## C++ Solution
```cpp
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(endGene)) return -1;
        queue<string> q;
        unordered_set<string> seen{{startGene}};
        q.push(startGene);
        int steps = 0;
        string genes = "ACGT";
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string cur = q.front(); q.pop();
                if (cur == endGene) return steps;
                for (int i = 0; i < (int)cur.size(); i++) {
                    char old = cur[i];
                    for (char g : genes) {
                        cur[i] = g;
                        if (dict.count(cur) && !seen.count(cur)) {
                            seen.insert(cur);
                            q.push(cur);
                        }
                    }
                    cur[i] = old;
                }
            }
            steps++;
        }
        return -1;
    }
};
```
