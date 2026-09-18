#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_222_countNodes {
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
        int countNodes(TreeNode* root) {
            int lenl = 0, lenr = 0;
            TreeNode* r = root, * l = root;
            while (l != NULL)
            {
                l = l->left;
                lenl++;
            }
            while (r != NULL)
            {
                r = r->right;
                lenr++;
            }
            if (lenl == lenr) return pow(2, lenl) - 1;
            return countNodes(root->right) + countNodes(root->left) + 1;
        }
    };
    bool CheckCase(TreeNode* root, const int& expected, string& message) {
        Solution solver;
        const int actual = solver.countNodes(root);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(&TreeNode(1, &TreeNode(2, &TreeNode(4), &TreeNode(5)), &TreeNode(3, &TreeNode(6),NULL)), 6, message)) {
            return false;
        }
        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("222.countNodes", RunChecks);
}