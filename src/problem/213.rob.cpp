#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_213_rob {
    class Solution {
    public:
		int rob1(int start, int end, vector<int>& nums) {
			int prev = 0, curr = 0,ans=0;
			for (int i = start; i <= end; ++i) {
				int temp = max(curr, prev + nums[i]);
				prev = curr;
				curr = temp;
			}
			return curr;
		}
        int rob(vector<int>& nums) {
            int len = nums.size();
			return max(rob1(1, len - 1, nums), nums[0] + rob1(2, len - 2, nums));
        }
    };
    bool CheckCase(vector<int> nums, const int& expected, string& message) {
        Solution solver;
        const int actual = solver.rob(nums);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{2,3,2}, 3, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("213.rob", RunChecks);
}