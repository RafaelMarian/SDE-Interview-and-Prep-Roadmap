/*
 * Trie (prefix tree) for FAANG interviews
 */

#include <iostream>
#include <string>
#include <vector>

struct TrieNode {
    TrieNode* children[26]{};
    bool isEnd = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}

    void insert(const std::string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) cur->children[i] = new TrieNode();
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }

    bool search(const std::string& word) const {
        TrieNode* node = find(word);
        return node && node->isEnd;
    }

    bool startsWith(const std::string& prefix) const {
        return find(prefix) != nullptr;
    }

    // Shortest dictionary root that is a prefix of word (Replace Words)
    std::string shortestRoot(const std::string& word) const {
        TrieNode* cur = root;
        std::string prefix;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) break;
            cur = cur->children[i];
            prefix.push_back(c);
            if (cur->isEnd) return prefix;
        }
        return word;
    }

private:
    TrieNode* find(const std::string& s) const {
        TrieNode* cur = root;
        for (char c : s) {
            int i = c - 'a';
            if (!cur->children[i]) return nullptr;
            cur = cur->children[i];
        }
        return cur;
    }
};

int main() {
    Trie t;
    t.insert("apple");
    t.insert("app");
    std::cout << std::boolalpha
              << t.search("apple") << "\n"      // true
              << t.search("app") << "\n"        // true
              << t.search("appl") << "\n"       // false
              << t.startsWith("appl") << "\n";  // true

    Trie dict;
    for (auto w : {"cat", "bat", "rat"}) dict.insert(w);
    std::cout << dict.shortestRoot("cattle") << "\n";  // cat
    std::cout << dict.shortestRoot("dog") << "\n";     // dog
    return 0;
}
