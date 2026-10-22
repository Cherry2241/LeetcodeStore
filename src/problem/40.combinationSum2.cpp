#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include<algorithm>
using namespace std;
namespace problem_40_combinationSum2 {
    class Solution {
    public:
        vector<vector<int>> ans;
        vector<int> nums;
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            find(candidates, target, 0);
            return ans;
        }
        void find(vector<int>& candidates, int target, int pos)
        {
            if (target == 0) {
                ans.push_back(nums);
                return;
            }
            if (target < 0) return;
            if (pos >= candidates.size()) return;
            int num = candidates[pos], end = pos + 1, j, len = candidates.size();
            if (target < num) return;
            while (end < len && candidates[end] == num)
            {
                end++;
            }
            find(candidates, target, end);
            for (j = 1;j <= end - pos;j++)
            {
                nums.push_back(num);
                find(candidates, target - j * num, end);
            }
            for (j = 1;j <= end - pos;j++)
            {
                nums.pop_back();
            }
        }
    };
    bool CheckCase(vector<int> candidates, int target, const vector<vector<int>>& expected, string& message) {
        Solution solver;
        vector<vector<int>> actual = solver.combinationSum2(candidates, target);
        sort(actual.begin(), actual.end());
        if (expected == actual) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{10, 1, 2, 7, 6, 1, 5}, 8, vector<vector<int>>{{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("40.combinationSum2", RunChecks);
}