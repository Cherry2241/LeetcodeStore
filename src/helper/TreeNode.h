#pragma once

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* leftNode, TreeNode* rightNode)
        : val(value), left(leftNode), right(rightNode) {}
};
