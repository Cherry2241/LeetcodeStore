#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_111_fourSum {
     struct TreeNode {
          int val;
          TreeNode *left;
          TreeNode *right;
          TreeNode() : val(0), left(nullptr), right(nullptr) {}
          TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
          TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
      };
    class Solution {
    public:
        bool hasPathSum(TreeNode* root, int targetSum) {
            if (root == NULL)
            {
                return false;
            }
            if (root->left == NULL && root->right == NULL)
            {
                return root->val == targetSum;
            }
            bool l = hasPathSum(root->left, targetSum - root->val), r = hasPathSum(root->right, targetSum - root->val);
            if (l || r) return true;
            else return false;
        }
    };
}