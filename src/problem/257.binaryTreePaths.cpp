#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include"helper/TreeNodeHelper.h"
using namespace std;
namespace problem_257_binaryTreePaths {
    class Solution {
    public:
        vector<string> ans;
        void find(TreeNode* head, string path)
        {
            path = path + to_string(head->val);
            if (head->left == NULL && head->right == NULL)
            {
                ans.push_back(path);
                return;
            }
            path = path + "->";
            if (head->left != NULL) find(head->left, path);
            if (head->right != NULL) find(head->right, path);
            
        }
        vector<string> binaryTreePaths(TreeNode* root) {
            find(root, "");
            return ans;
        }
    };
    bool CheckCase(TreeNode* root, const vector<string>& expected, string& message) {
	    Solution solver;
	    const vector<string> actual = solver.binaryTreePaths(root);
	    if (actual == expected) {
		    return true;
	    }

	    message = "CheckCase failed";
	    return false;
    }

    bool RunChecks(std::string& message) {
	    if (!CheckCase(helper::MakeTree({ 1,2,3,nullptr,5,nullptr,nullptr}), vector<string>{"1->2->5", "1->3"}, message)) {
		    return false;
	    }

	    message = "1 cases passed";
	    return true;
    }
    ProblemRegistrar registrar("257.binaryTreePaths", RunChecks);
}