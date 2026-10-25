#include <string>
#include<algorithm>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_78_subsets {
    class Solution {
    public:
        vector<vector<int>> ans;
        vector<int> path;
        vector<vector<int>> subsets(vector<int>& nums) {
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
            find(nums, pos + 1);
            path.push_back(nums[pos]);
            find(nums, pos + 1);
            path.pop_back();
        }
    };
    bool CheckCase(vector<int> s, const vector<vector<int>>& expected, string& message) {
        Solution solver;
        vector<vector<int>> actual = solver.subsets(s);
        sort(actual.begin(), actual.end());
        if (expected == actual) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{1, 2, 3}, vector<vector<int>>{{}, { 1 }, { 1,2 }, { 1,2,3 }, { 1,3 }, { 2 }, { 2, 3 }, { 3 }}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("78.subsets", RunChecks);
}