#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_53_maxSubArray {
    class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int i, len = nums.size(), sum = 0, ans = nums[0];
            for (i = 0;i < len;i++)
            {
                sum = sum + nums[i];
                ans = max(ans, sum);
                if (sum < 0) sum = 0;
            }
            return ans;
        }
    };
    bool CheckCase(vector<int> nums, const int& expected, string& message) {
        Solution solver;
        const int actual = solver.maxSubArray(nums);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("53.maxSubArray", RunChecks);
}