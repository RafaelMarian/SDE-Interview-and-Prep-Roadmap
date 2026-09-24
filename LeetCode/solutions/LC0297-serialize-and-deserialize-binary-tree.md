# LC 297. Serialize and Deserialize Binary Tree
**Lists:** Blind 75 · Top 150  
**Topic:** Trees  
**Difficulty:** Hard

## Problem (short + example)

Design an algorithm to serialize a binary tree to a string and deserialize that string back to the same tree structure.

**Example:** `[1,2,3,null,null,4,5]` ↔ string → same tree.

## Intuition

Preorder with explicit null markers uniquely describes the tree. Deserialize by reading tokens in the same order.

## Approach

**Serialize:** DFS preorder; append `val,` or `#,` for null.  
**Deserialize:** Parse comma-separated tokens; build from index with recursive preorder.

## Complexity

- **Time:** O(n) serialize and deserialize  
- **Space:** O(n) for string and recursion

## C++ Solution

```cpp
class Codec {
public:
    void serializePreorder(TreeNode* root, std::string& out) {
        if (!root) {
            out += "#,";
            return;
        }
        out += std::to_string(root->val) + ',';
        serializePreorder(root->left, out);
        serializePreorder(root->right, out);
    }

    std::string serialize(TreeNode* root) {
        std::string out;
        serializePreorder(root, out);
        return out;
    }

    TreeNode* deserializePreorder(const std::vector<std::string>& tokens, int& i) {
        if (i >= static_cast<int>(tokens.size()) || tokens[i] == "#") {
            ++i;
            return nullptr;
        }
        TreeNode* node = new TreeNode(std::stoi(tokens[i++]));
        node->left = deserializePreorder(tokens, i);
        node->right = deserializePreorder(tokens, i);
        return node;
    }

    TreeNode* deserialize(std::string data) {
        std::vector<std::string> tokens;
        std::stringstream ss(data);
        std::string tok;
        while (std::getline(ss, tok, ',')) {
            if (!tok.empty()) tokens.push_back(tok);
        }
        int i = 0;
        return deserializePreorder(tokens, i);
    }
};
```
