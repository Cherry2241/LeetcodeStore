#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include "helper/TreeNodeHelper.h"
using namespace std;
namespace problem_700_searchBST {
    class Solution {
    public:
        TreeNode* searchBST(TreeNode* root, int val) {
            while (root != NULL && root->val != val)
            {
                if (root->val < val) root = root->right;
                else root = root->left;
            }
            return root;
        }
    };
    bool CheckCase(TreeNode* root,int val, TreeNode* expected, string& message) {
        Solution solver;
        TreeNode* actual = solver.searchBST(root, val);
        if (helper::IsSameTree(actual, expected)) {
            return true;
        }
        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        {
            TreeNode* root1 = helper::MakeTree({ 4,2,7,1,3 });
            TreeNode* expected = helper::MakeTree({2,1,3 });
            if (!CheckCase(root1,2, expected, message)) {
                return false;
            }

        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("700.searchBST", RunChecks);
}