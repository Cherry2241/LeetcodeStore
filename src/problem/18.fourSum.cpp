#include<vector>
#include <string>
#include<algorithm>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_18_fourSum {
    class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int len = nums.size(), a, b, c, d;
            vector<vector<int>> ans;
            if (len < 4) return ans;
            sort(nums.begin(), nums.end());
            for (a = 0;a < len - 3;a++){
                if (a > 0 && nums[a] == nums[a - 1]) continue;
                if ((long)nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) break;
                if ((long)nums[a] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target) continue;
                for (b = a + 1;b < len - 2;b++){
                    if (b > a + 1 && nums[b] == nums[b - 1]) continue;
                    if ((long)nums[a] + nums[b] + nums[b + 1] + nums[b + 2] > target) break;
                    if ((long)nums[a] + nums[len - 1] + nums[len - 2] + nums[b] < target) continue;
                    d = len - 1;
                    for (c = b + 1;c < d;c++)
                    {
                        if (c > b + 1 && nums[c] == nums[c - 1]) continue;
                        while (c<d && (long)nums[a] + nums[b] + nums[c] + nums[d]>(long)target) d--;
                        if (c != d && (long)nums[a] + nums[b] + nums[c] + nums[d] == target)
                        {
                            ans.push_back({ nums[a],nums[b],nums[c],nums[d] });
                            d--;
                        }
                    }
                }
            }
            return ans;
        }
    };
    bool CheckCase(vector<int> nums,int target, const vector<vector<int>>& expected, string& message) {
        Solution solver;
        const vector<vector<int>> actual = solver.fourSum(nums,target);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{1, 0, -1, 0, -2, 2}, 0, vector<vector<int>> {{-2, -1, 1, 2},{-2,0,0,2},{-1,0,0,1}}, message)) {
            return false;
        }
        if (!CheckCase(vector<int>{2, 2, 2, 2, 2}, 8, vector<vector<int>> {{2, 2, 2, 2}}, message)) {
            return false;
        }

        message = "2 cases passed";
        return true;
    }
    ProblemRegistrar registrar("18.fourSum", RunChecks);
}