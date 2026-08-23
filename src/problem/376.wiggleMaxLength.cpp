#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_376_wiggleMaxLength {
    class Solution {
    public:
        int wiggleMaxLength(vector<int>& nums) {
            int maxLen = 1, len = nums.size(), i, dis1, dis2 = 0;
            if (len <= 1) return len;
            for (i = 1;i < len;i++)
            {
                dis1 = nums[i] - nums[i - 1];
                if (dis1 == 0) continue;
                if (dis1 * dis2 < 0)
                {
                    maxLen++;
                    dis2 = dis1;
                }
                if (dis2 == 0)
                {
                    dis2 = dis1;
                    maxLen++;
                }
            }
            return maxLen;
        }
    };
    bool CheckCase(vector<int> nums,const int& expected, string& message) {
        Solution solver;
        const int actual = solver.wiggleMaxLength(nums);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 2 , message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("376.wiggleMaxLength", RunChecks);
}