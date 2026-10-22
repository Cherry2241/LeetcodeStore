#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include<algorithm>
using namespace std;
namespace problem_39_combinationSum {
    class Solution {
    public:
        vector<vector<int>> ans;
        vector<int> nums;
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            find(candidates, target, 0);
            return ans;
        }
        void find(vector<int>& candidates, int target, int pos)
        {
            if (target == 0) {
                ans.push_back(nums);
                return;
            }
            if (pos == candidates.size()) return;
            int i, num = candidates[pos];
            for (i = 0;i * num <= target;i++)
            {
                find(candidates, target - i * num, pos + 1);
                nums.push_back(num);
            }
            for (;i > 0;i--)
            {
                nums.pop_back();
            }
        }
    };
    bool CheckCase(vector<int> candidates, int target, const vector<vector<int>>& expected, string& message) {
        Solution solver;
        vector<vector<int>> actual = solver.combinationSum(candidates, target);
		sort(actual.begin(), actual.end());
        if (expected == actual) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{2,3,6,7},7,vector<vector<int>>{{2,2,3},{7}}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("39.combinationSum", RunChecks);
}