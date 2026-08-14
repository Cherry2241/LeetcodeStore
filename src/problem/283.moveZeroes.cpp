#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_283_moveZeroes {
    class Solution {
    public:
        vector<int> moveZeroes(vector<int>& nums) {
            int i, j = 0, len = nums.size();
            for (i = 0;i < len;i++)
            {
                if (nums[i] != 0)
                {
                    if (j < i)
                    {
                        swap(nums[i], nums[j]);
                    }
                    j++;
                }
            }
            return nums;
        }
    };
    bool CheckCase(vector<int> nums, const vector <int> &expected, string& message) {
        Solution solver;
        const vector<int> actual = solver.moveZeroes(nums);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{0, 1, 0, 3, 12}, vector<int>{1, 3, 12, 0, 0}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("283.Move Zeroes", RunChecks);
}