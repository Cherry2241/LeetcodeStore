#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_111_fourSum {
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
        int minDepth(TreeNode* root) {
            if (root == NULL) return 0;
            if (root->left == NULL && root->right == NULL) return 1;
            int deep = INT_MAX;
            if (root->left != NULL) deep = min(minDepth(root->left), deep);
            if (root->right != NULL) deep = min(minDepth(root->right), deep);
            return deep + 1;
        }
    };
    bool CheckCase(TreeNode* root,const int& expected, string& message) {
        Solution solver;
        const int actual = solver.minDepth(root);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(&TreeNode(3,&TreeNode(9),&TreeNode(20, &TreeNode(15),&TreeNode(7))), 2, message)) {
            return false;
        }
        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("111.minDepth", RunChecks);
}