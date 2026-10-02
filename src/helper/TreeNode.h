#pragma once

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* leftNode, TreeNode* rightNode)
        : val(value), left(leftNode), right(rightNode) {}
};

namespace helper {

inline bool IsSameTree(const TreeNode* first, const TreeNode* second) {
    if (first == nullptr || second == nullptr) {
        return first == second;
    }

    return first->val == second->val &&
           IsSameTree(first->left, second->left) &&
           IsSameTree(first->right, second->right);
}

}  // namespace helper
