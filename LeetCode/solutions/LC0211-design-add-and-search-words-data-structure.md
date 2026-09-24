# LC 211. Design Add and Search Words Data Structure
**Lists:** Blind 75 · Top 150  
**Topic:** Tries  
**Difficulty:** Medium

## Problem (short + example)

Implement `WordDictionary` supporting `addWord(word)` and `search(word)` where `'.'` matches any letter.

**Example:** Add `"bad"`, `"dad"`, `"mad"`; `search("pad")` → false; `search(".ad")` → true.

## Intuition

Store words in a trie. For search without wildcards, walk the trie. With `'.'`, try all 26 children at that step (DFS/backtracking).

## Approach

1. Trie node with 26 children and `end` flag.
2. **addWord:** standard trie insert.
3. **search:** recursive helper at index `i`; on `'.'`, recurse to any existing child; else follow matching letter.

## Complexity

- **addWord:** O(m)  
- **search:** O(26^d) worst case with many `'.'`, O(m) for plain words  
- **Space:** O(total stored characters)

## C++ Solution

```cpp
class WordDictionary {
    struct Node {
        std::array<Node*, 26> next{};
        bool end = false;
        ~Node() {
            for (Node* c : next) delete c;
        }
    };
    Node* root;

    bool dfs(const std::string& word, int i, Node* node) {
        if (!node) return false;
        if (i == static_cast<int>(word.size())) return node->end;
        char ch = word[i];
        if (ch == '.') {
            for (Node* child : node->next) {
                if (child && dfs(word, i + 1, child)) return true;
            }
            return false;
        }
        int idx = ch - 'a';
        return dfs(word, i + 1, node->next[idx]);
    }

public:
    WordDictionary() : root(new Node()) {}

    void addWord(const std::string& word) {
        Node* cur = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (!cur->next[i]) cur->next[i] = new Node();
            cur = cur->next[i];
        }
        cur->end = true;
    }

    bool search(const std::string& word) {
        return dfs(word, 0, root);
    }
};
```
