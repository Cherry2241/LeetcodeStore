#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include "helper/TreeNodeHelper.h"
using namespace std;
namespace problem_654_constructMaximumBinaryTree {
    class Solution {
    public:
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            return build(nums, 0, nums.size() - 1);
        }
        TreeNode* build(vector<int>& nums, int start, int end)
        {
            if (start == end) return new TreeNode(nums[end]);
            if (start > end) return nullptr;
            int pos = 0, i, maxValue = 0;
            for (i = start;i <= end;i++)
            {
                if (nums[i] > maxValue)
                {
                    maxValue = nums[i];
                    pos = i;
                }
            }
            TreeNode* l = build(nums, start, pos - 1), * r = build(nums, pos + 1, end);
            return new TreeNode(maxValue, l, r);
        }
    };
}