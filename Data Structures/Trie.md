# Trie (Prefix Tree)

Tree where each edge is a character. Perfect for prefix search and word dictionaries.

## Structure

```cpp
struct TrieNode {
    TrieNode* children[26]{};
    bool isEnd = false;
};
```

Alternatively `unordered_map<char, TrieNode*>` for larger alphabets.

## Operations

| Op | Time |
|----|------|
| Insert word | O(L) |
| Search word | O(L) |
| Starts with prefix | O(L) |

L = word length. Space can be large → often acceptable for interview.

## When it shows up

- Implement Trie (LC 208)
- Word Search II (board + dictionary)
- Autocomplete / replace words
- Longest word with all prefixes

## Pattern sketch

```cpp
void insert(TrieNode* root, const string& w) {
    TrieNode* cur = root;
    for (char c : w) {
        int i = c - 'a';
        if (!cur->children[i]) cur->children[i] = new TrieNode();
        cur = cur->children[i];
    }
    cur->isEnd = true;
}
```

## Practice
| # | Problem |
|---|---------|
| LC 208 | Implement Trie |
| LC 211 | Design Add and Search Words |
| LC 212 | Word Search II |
| LC 648 | Replace Words |

See [`Trie.cpp`](./Trie.cpp).
