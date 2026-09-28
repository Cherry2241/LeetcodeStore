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
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            if (nums.empty())
            {
                return NULL;
            }
            int len = nums.size(), pos = len / 2;
            if (len == 1)
            {
                TreeNode* c = new TreeNode(nums[0]);
                return c;
            }
            vector<int> l(nums.begin(), nums.begin() + pos);
            vector<int> r(nums.begin() + pos + 1, nums.end());
            return new TreeNode(nums[pos], sortedArrayToBST(l), sortedArrayToBST(r));
        }
    };
}