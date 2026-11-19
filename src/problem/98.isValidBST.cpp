#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include "helper/TreeNodeHelper.h"
using namespace std;
namespace problem_98_isValidBST{
    class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            return isBST(root, LONG_MIN, LONG_MAX);
        }
        bool isBST(TreeNode* root, long long minn, long long maxn)
        {
            if (root == NULL) return true;
            if (root->val <= minn || root->val >= maxn) return false;
            return isBST(root->left, minn, root->val) && isBST(root->right, root->val, maxn);
        }
    };
    bool CheckCase(TreeNode* root,bool expected, string& message) {
        Solution solver;
        bool actual = solver.isValidBST(root);
        if (actual==expected) {
            return true;
        }
        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        TreeNode* root = helper::MakeTree({ 5,1,4,nullptr,nullptr,3,6 });
        if (!CheckCase(root, false, message)) {
                return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("98.isValidBST", RunChecks);
}