#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_55_canJump {
    class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int maxMove = 0, i, len = nums.size();
            for (i = 0;i < len;i++)
            {
                if (maxMove < i) return false;
                maxMove = max(maxMove, i + nums[i]);
                if (maxMove >= len - 1) return true;
            }
            return true;
        }
    };
    bool CheckCase(vector<int> nums, const bool& expected, string& message) {
        Solution solver;
        const bool actual = solver.canJump(nums);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{2, 3, 1, 1, 4}, true, message)) {
            return false;
        }
        if (!CheckCase(vector<int>{3, 2, 1, 0, 4}, false, message)) {
            return false;
        }

        message = "2 cases passed";
        return true;
    }
    ProblemRegistrar registrar("55.canJump", RunChecks);
}