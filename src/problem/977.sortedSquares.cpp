#include<vector>
#include <string>
#include<algorithm>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_977_sortedSquares {
    class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            vector<int> ans;
            int i, j;
            for (i = 0;i < nums.size();i++)
            {
                if (nums[i] > 0) break;
            }
            j = i - 1;
            while (j >= 0 && i < nums.size())
            {
                if (-nums[j] > nums[i])
                {
                    ans.push_back(nums[i] * nums[i]);
                    i++;
                }
                else
                {
                    ans.push_back(nums[j] * nums[j]);
                    j--;
                }
            }
            for (;j >= 0;j--) ans.push_back(nums[j] * nums[j]);
            for (;i < nums.size();i++) ans.push_back(nums[i] * nums[i]);
            return ans;
        }
    };
    bool CheckCase(vector<int> nums, const vector<int>& expected, string& message) {
        Solution solver;
        const vector<int> actual = solver.sortedSquares(nums);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{ -4, -1, 0, 3, 10 }, vector<int>{ 0, 1, 9, 16, 100}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("977.sortedSquares", RunChecks);
}