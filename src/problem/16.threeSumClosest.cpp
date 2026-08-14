#include<vector>
#include <string>
#include<algorithm>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_16_threeSumClosest {
    class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int len = nums.size(), i, j, k, sum = 100000, dis;
            sort(nums.begin(), nums.end());
            for (i = 0;i < len;i++)
            {
                k = len - 1;
                for (j = i + 1;j < len - 1 && j < k;j++)
                {
                    while (j<k && nums[i] + nums[j] + nums[k]>target)
                    {
                        k--;
                    }
                    if (j != k)
                    {
                        dis = abs(nums[i] + nums[j] + nums[k] - target);
                        if (abs(sum - target) > dis) sum = nums[i] + nums[j] + nums[k];
                    }
                    if (k + 1 < len)
                    {
                        dis = abs(nums[i] + nums[j] + nums[k + 1] - target);
                        if (abs(sum - target) > dis) sum = nums[i] + nums[j] + nums[k + 1];
                    }
                    if (sum == target) return sum;
                }
            }
            return sum;
        }
    };
    bool CheckCase(vector<int> nums, int target, int expected, string& message) {
        Solution solver;
        int actual = solver.threeSumClosest(nums, target);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(string& message) {
        if (!CheckCase(vector<int>{ -1, 2, 1, -4}, 1, 2, message)) {
            return false;
        }
        message = "1 cases passed";
        return true;
    }

    ProblemRegistrar registrar("16.Three Sum Closest", RunChecks);
}