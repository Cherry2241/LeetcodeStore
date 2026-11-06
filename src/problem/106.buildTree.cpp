#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include "helper/TreeNodeHelper.h"
using namespace std;
namespace problem_106_buildTree {
    class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int len = postorder.size();
            return build(inorder, postorder, 0, len - 1, 0, len - 1);
        }
        TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l1, int r1, int l2, int r2) {
            int len = r1 - l1 + 1, i;
            if (len == 1) return new TreeNode(postorder[r2]);
            if (len == 0) return nullptr;
            int val = postorder[r2];
            for (i = 0;i < len;i++)
            {
                if (inorder[l1 + i] != val) continue;
                break;
            }
            TreeNode* l = build(inorder, postorder, l1, l1 + i - 1, l2, l2 + i - 1);
            TreeNode* r = build(inorder, postorder, l1 + i + 1, r1, l2 + i, r2 - 1);
            TreeNode* root = new TreeNode(val, l, r);
            return root;
        }
    };
    bool CheckCase(vector<int>& inorder, vector<int>& postorder,TreeNode* expected, string& message) {
        Solution solver;
        TreeNode* actual = solver.buildTree(inorder, postorder);
       if (helper::IsSameTree(expected, actual)) {
           return true;
        }
        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{ 9,3,15,20,7 },vector<int>{ 9, 15, 7, 20, 3 },helper::MakeTree({3, 9, 20, nullptr, nullptr, 15, 7}), message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("106.buildTree", RunChecks);
}