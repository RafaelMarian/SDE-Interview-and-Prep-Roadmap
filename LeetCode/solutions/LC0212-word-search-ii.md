# LC 212. Word Search II
**Lists:** Blind 75 · Top 150  
**Topic:** Tries  
**Difficulty:** Hard

## Problem (short + example)

Given an `m × n` board of characters and a list of strings `words`, return all words that can be formed by sequentially adjacent cells (no reuse per word).

**Example:** Board `[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]`, words `["oath","pea","eat","rain"]` → `["eat","oath"]`.

## Intuition

Put all `words` in a trie. DFS from each cell following trie edges; when a node is an end-of-word, add the word. Prune when trie branch is dead.

## Approach

1. Build trie from `words`; store pointer to word string at terminal nodes.
2. For each cell, DFS with `(row, col, trieNode)`.
3. Mark visited, explore 4 neighbors matching next char, backtrack.
4. Optional: remove trie branch after collecting a word to avoid duplicates.

## Complexity

- **Time:** O(m × n × 4^L) with pruning; trie build O(total chars)  
- **Space:** O(total chars) for trie + O(L) recursion

## C++ Solution

```cpp
class Solution {
    struct TrieNode {
        std::array<TrieNode*, 26> next{};
        std::string* word = nullptr;
        ~TrieNode() {
            for (TrieNode* c : next) delete c;
        }
    };

    void insert(TrieNode* root, const std::string& w) {
        TrieNode* cur = root;
        for (char ch : w) {
            int i = ch - 'a';
            if (!cur->next[i]) cur->next[i] = new TrieNode();
            cur = cur->next[i];
        }
        cur->word = new std::string(w);
    }

    void dfs(std::vector<std::vector<char>>& board, int r, int c, TrieNode* node,
             std::vector<std::string>& ans) {
        if (r < 0 || c < 0 || r >= static_cast<int>(board.size()) ||
            c >= static_cast<int>(board[0].size()))
            return;
        char ch = board[r][c];
        if (ch == '#') return;
        TrieNode* next = node->next[ch - 'a'];
        if (!next) return;

        if (next->word) {
            ans.push_back(*next->word);
            delete next->word;
            next->word = nullptr;
        }

        board[r][c] = '#';
        dfs(board, r + 1, c, next, ans);
        dfs(board, r - 1, c, next, ans);
        dfs(board, r, c + 1, next, ans);
        dfs(board, r, c - 1, next, ans);
        board[r][c] = ch;
    }

public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board,
                                       std::vector<std::string>& words) {
        TrieNode* root = new TrieNode();
        for (const std::string& w : words) insert(root, w);

        std::vector<std::string> ans;
        for (int r = 0; r < static_cast<int>(board.size()); ++r) {
            for (int c = 0; c < static_cast<int>(board[0].size()); ++c)
                dfs(board, r, c, root, ans);
        }
        delete root;
        return ans;
    }
};
```
