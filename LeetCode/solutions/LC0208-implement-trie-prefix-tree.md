# LC 208. Implement Trie (Prefix Tree)
**Lists:** Blind 75 · Top 150  
**Topic:** Tries  
**Difficulty:** Medium

## Problem (short + example)

Implement a trie with `insert`, `search` (exact word), and `startsWith` (prefix).

**Example:** Insert `"apple"`; `search("apple")` → true; `startsWith("app")` → true.

## Intuition

Each node holds children for next characters and a flag for end-of-word. Walk characters for insert/search; prefix search stops early if path exists.

## Approach

1. Root node with `children[26]` and `end`.
2. **insert:** walk/create nodes per char; mark last `end = true`.
3. **search:** walk and require `end` at last char.
4. **startsWith:** walk only; return true if path exists.

## Complexity

- **Time:** O(m) per operation, m = word length  
- **Space:** O(total characters stored)

## C++ Solution

```cpp
class Trie {
    struct Node {
        std::array<Node*, 26> next{};
        bool end = false;
        ~Node() {
            for (Node* c : next)
                delete c;
        }
    };
    Node* root;

public:
    Trie() : root(new Node()) {}

    void insert(const std::string& word) {
        Node* cur = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (!cur->next[i]) cur->next[i] = new Node();
            cur = cur->next[i];
        }
        cur->end = true;
    }

    bool search(const std::string& word) {
        Node* node = find(word);
        return node && node->end;
    }

    bool startsWith(const std::string& prefix) {
        return find(prefix) != nullptr;
    }

private:
    Node* find(const std::string& s) {
        Node* cur = root;
        for (char ch : s) {
            int i = ch - 'a';
            if (!cur->next[i]) return nullptr;
            cur = cur->next[i];
        }
        return cur;
    }
};
```
