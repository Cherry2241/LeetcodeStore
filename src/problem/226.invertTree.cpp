#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_226_invertTree {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };
    class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            if (root == nullptr) return nullptr;
            TreeNode* l = invertTree(root->left), * r = invertTree(root->right);
            root->left = r;
            root->right = l;
            return root;
        }

    };
}