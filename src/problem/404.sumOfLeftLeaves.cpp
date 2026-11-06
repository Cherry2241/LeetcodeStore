#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include "helper/TreeNodeHelper.h"
using namespace std;
namespace problem_404_sumOfLeftLeaves  {
    class Solution {
    public:
        int sumOfLeftLeaves(TreeNode* root) {
            return find(root, 0);
        }
        int find(TreeNode* root, bool ifLeft)
        {
            if (root == NULL) return 0;
            if (root->left == NULL && root->right == NULL)
            {
                if (ifLeft) return root->val;
                else return 0;
            }
            int num = find(root->left, 1) + find(root->right, 0);
            return num;
        }
    };
    bool CheckCase(TreeNode* s, const int& expected, string& message) {
        Solution solver;
        int actual = solver.sumOfLeftLeaves(s);
        if (expected == actual) {
            return true;
        }
        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(helper::MakeTree({ 3,9,20,nullptr,nullptr,15,7 }), 24, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("404.sumOfLeftLeaves", RunChecks);
}