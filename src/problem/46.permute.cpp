#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include<algorithm>
using namespace std;
namespace problem_46_permute {
    class Solution {
    public:
        vector<vector<int>> ans;
        vector<int> path;
        vector<vector<int>> permute(vector<int>& nums) {
            find(nums, 0);
            return ans;
        }
        void find(vector<int>& nums, int pos)
        {
            if (pos == nums.size())
            {
                ans.push_back(path);
                return;
            }
            int i, len = nums.size();
            for (i = pos;i < len;i++)
            {
                swap(nums[pos], nums[i]);
                path.push_back(nums[pos]);
                find(nums, pos + 1);
                swap(nums[pos], nums[i]);
                path.pop_back();
            }
        }
    };
    bool CheckCase(vector<int> s, const vector<vector<int>>& expected, string& message) {
        Solution solver;
        vector<vector<int>> actual = solver.permute(s);
        sort(actual.begin(), actual.end());
        if (expected == actual) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{1,2,3}, vector<vector<int>>{ { 1, 2, 3 }, { 1, 3, 2 }, { 2, 1, 3 }, { 2, 3, 1 }, { 3, 1, 2 }, { 3, 2, 1 }}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("46.permute", RunChecks);
}