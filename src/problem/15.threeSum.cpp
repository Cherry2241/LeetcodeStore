#include<vector>
#include <string>
#include<algorithm>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_15_threeSum {
    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int len = nums.size(), i, j, k;
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            for (i = 0;i < len - 2;i++)
            {
                if (i > 0 && nums[i - 1] == nums[i]) continue;
                k = len - 1;
                for (j = i + 1;j < len - 1 && j < k;j++)
                {
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                    while (j < k && nums[i] + nums[j] + nums[k]>0) k--;
                    if (j != k && nums[i] + nums[j] + nums[k] == 0)
                    {
                        ans.push_back({ nums[i],nums[j],nums[k] });
                    }
                }
            }
            return ans;
        }
    };
    bool CheckCase(vector<int> nums, const vector<vector<int>>& expected, string& message) {
        Solution solver;
        const vector<vector<int>> actual = solver.threeSum(nums);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{1,2,-2,-1 }, {}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("15.Three Sum", RunChecks);
}
