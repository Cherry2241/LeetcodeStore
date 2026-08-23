#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_45_jump {
    class Solution {
    public:
        int jump(vector<int>& nums) {
            int len = nums.size(), i, maxMove = 0, end = 0, ans = 0;
            for (i = 0;i < len - 1;i++)
            {
                maxMove = max(maxMove, i + nums[i]);
                if (i == end)
                {
                    end = maxMove;
                    ans++;
                }
            }
            return ans;
        }
    };
    bool CheckCase(vector<int> nums, const int& expected, string& message) {
        Solution solver;
        const int actual = solver.jump(nums);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{ 2, 3, 1, 1, 4}, 2, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("45.jump", RunChecks);
}