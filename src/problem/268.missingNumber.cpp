#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_268_missingNumber {
    class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size(), sum = n * (n + 1) / 2, i;
            for (i = 0;i < n;i++) sum = sum - nums[i];
            return sum;
        }
    };
    bool CheckCase(vector<int> nums, const int& expected, string& message) {
        Solution solver;
        const int actual = solver.missingNumber(nums);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{0,3,1}, 2, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("268.missingNumber", RunChecks);
}