# LC 433. Minimum Genetic Mutation

**Lists:** Top 150
**Topic:** Graphs (BFS)
**Difficulty:** Medium

## Problem
A gene string has eight characters from `'A','C','G','T'`. One mutation changes one character. Given `startGene`, `endGene`, and `bank` of valid genes, return the minimum number of mutations to reach `endGene`, or `-1` if impossible. Each step must use a word in `bank`. Example: `start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]` → `1`.

## Intuition
Same as word ladder: genes are nodes; edges connect strings differing by one character and present in the bank. Shortest path is BFS.

## Approach
1. Put `bank` in a hash set; if `endGene` not in set, return `-1`.
2. BFS queue with `(gene, steps)` from `startGene`.
3. For each gene, try all 4 letters at each of 8 positions; if neighbor in set, enqueue with `steps + 1` and remove from set.
4. Return steps when `endGene` is reached.

## Complexity
- Time: O(8 · 4 · n · L) with n bank size, L = 8
- Space: O(n)

## C++ Solution
```cpp
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(endGene)) {
            return -1;
        }
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        dict.erase(startGene);
        const string letters = "ACGT";
        while (!q.empty()) {
            auto [gene, steps] = q.front();
            q.pop();
            if (gene == endGene) {
                return steps;
            }
            for (int i = 0; i < 8; ++i) {
                char orig = gene[i];
                for (char c : letters) {
                    if (c == orig) {
                        continue;
                    }
                    gene[i] = c;
                    if (dict.count(gene)) {
                        if (gene == endGene) {
                            return steps + 1;
                        }
                        dict.erase(gene);
                        q.push({gene, steps + 1});
                    }
                }
                gene[i] = orig;
            }
        }
        return -1;
    }
};
```
