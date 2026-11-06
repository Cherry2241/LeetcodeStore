#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include "helper/TreeNodeHelper.h"
using namespace std;
namespace problem_513_findBottomLeftValue {
    class Solution {
    public:
        int maxdep = 0, val;
        int findBottomLeftValue(TreeNode* root) {
            find(root, 1);
            return val;
        }
        void find(TreeNode* root, int dep)
        {
            if (root == NULL) return;
            if (root->left == NULL && root->right == NULL)
            {
                if (dep > maxdep)
                {
                    val = root->val;
                    maxdep = dep;
                }
                return;
            }
            find(root->left, dep + 1);
            find(root->right, dep + 1);
        }
    };
    bool CheckCase(TreeNode* s, const int& expected, string& message) {
        Solution solver;
        int actual = solver.findBottomLeftValue(s);
        if (expected == actual) {
            return true;
        }
        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(helper::MakeTree({ 1,2,3,4,nullptr,5,6,nullptr,nullptr,7,nullptr,nullptr,nullptr}), 7, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("513.findBottomLeftValue", RunChecks);
}