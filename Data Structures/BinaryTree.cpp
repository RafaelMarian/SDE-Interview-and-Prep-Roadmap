/*
 * Binary Tree / BST patterns for FAANG interviews
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> ans;
    if (!root) return ans;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = static_cast<int>(q.size());
        std::vector<int> level;
        while (sz--) {
            TreeNode* n = q.front();
            q.pop();
            level.push_back(n->val);
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        ans.push_back(std::move(level));
    }
    return ans;
}

bool validate(TreeNode* node, long lo, long hi) {
    if (!node) return true;
    if (node->val <= lo || node->val >= hi) return false;
    return validate(node->left, lo, node->val) &&
           validate(node->right, node->val, hi);
}

bool isValidBST(TreeNode* root) {
    return validate(root, LONG_MIN, LONG_MAX);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* L = lowestCommonAncestor(root->left, p, q);
    TreeNode* R = lowestCommonAncestor(root->right, p, q);
    if (L && R) return root;
    return L ? L : R;
}

TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    //       4
    //      / \
    //     2   6
    //    / \
    //   1   3
    TreeNode* root = nullptr;
    for (int v : {4, 2, 6, 1, 3}) root = insertBST(root, v);

    std::cout << maxDepth(root) << "\n";              // 3
    std::cout << std::boolalpha << isValidBST(root) << "\n";  // true

    auto levels = levelOrder(root);
    for (auto& lvl : levels) {
        for (int x : lvl) std::cout << x << " ";
        std::cout << "| ";
    }
    std::cout << "\n";  // 4 | 2 6 | 1 3 |

    TreeNode* p = root->left;          // 2
    TreeNode* q = root->left->right;   // 3
    std::cout << lowestCommonAncestor(root, p, q)->val << "\n";  // 2

    invertTree(root);
    std::cout << root->left->val << " " << root->right->val << "\n";  // 6 2

    deleteTree(root);
    return 0;
}
