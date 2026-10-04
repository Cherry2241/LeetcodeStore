#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_136_singleNumber {
    class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int len = nums.size(), ret = 0;
            for (int i = 0;i < len;i++)
            {
                ret ^= nums[i];
            }
            return ret;
        }
    };
    bool CheckCase(vector<int> nums, const int& expected, string& message) {
        Solution solver;
        const  int actual = solver.singleNumber(nums);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{2,2,1}, 1, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("136.singleNumber", RunChecks);
}