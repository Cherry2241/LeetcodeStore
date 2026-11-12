#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include "helper/TreeNodeHelper.h"
using namespace std;
namespace problem_617_mergeTrees {
    class Solution {
    public:
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
            if (root1 == nullptr) return root2;
            if (root2 == nullptr) return root1;
            int v = root1->val + root2->val;
            TreeNode* l = mergeTrees(root1->left, root2->left), * r = mergeTrees(root1->right, root2->right);
            return new TreeNode(v, l, r);
        }
    };
    bool CheckCase(TreeNode* root1, TreeNode* root2, TreeNode* expected, string& message) {
        Solution solver;
        TreeNode* actual = solver.mergeTrees(root1,root2);
        if (helper::IsSameTree(actual, expected)) {
            return true;
        }
        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        {
            TreeNode* root1 = helper::MakeTree({ 1,3,2,5 });
            TreeNode* root2 = helper::MakeTree({ 2,1,3,nullptr,4,nullptr,7 });
            TreeNode* expected = helper::MakeTree({ 3,4,5,5,4,nullptr,7 });
            if (!CheckCase(root1, root2, expected, message)) {
                return false;
            }
            
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("617.mergeTrees", RunChecks);
}