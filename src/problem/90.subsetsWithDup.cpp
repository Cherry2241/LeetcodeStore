#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include<algorithm>
using namespace std;
namespace problem_90_subsetsWithDup {
    class Solution {
    public:
        vector<vector<int>> ans;
        vector<int> path;
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            find(nums, 0);
            return ans;
        }
        void find(vector<int>& nums, int pos)
        {
            if (pos >= nums.size())
            {
                ans.push_back(path);
                return;
            }
            int num = nums[pos], end = pos + 1, j, len = nums.size();
            path.push_back(num);
            find(nums, pos + 1);
            path.pop_back();
            while (end < len && nums[end] == num)
            {
                end++;
            }
            find(nums, end);
        }
    };
    bool CheckCase(vector<int> s, const vector<vector<int>>& expected, string& message) {
        Solution solver;
        vector<vector<int>> actual = solver.subsetsWithDup(s);
        sort(actual.begin(), actual.end());
        if (expected == actual) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{1, 2, 2}, vector<vector<int>>{{}, { 1 }, { 1,2 }, { 1,2,2 }, { 2 }, { 2, 2 }}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("90.subsetsWithDup", RunChecks);
}