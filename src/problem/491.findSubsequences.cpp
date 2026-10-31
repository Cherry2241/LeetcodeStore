#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include<algorithm>
using namespace std;
namespace problem_491_findSubsequences {
    class Solution {
    public:
        vector<vector<int>> ans;
        vector<int> path;
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            find(nums, 0, -1000);
            return ans;
        }
        void find(vector<int>& nums, int pos, int t)
        {
            if (pos == nums.size())
            {
                if (path.size() >= 2) ans.push_back(path);
                return;
            }
            if (nums[pos] != t)
            {
                find(nums, pos + 1, t);
            }
            if (nums[pos] >= t)
            {
                path.push_back(nums[pos]);
                find(nums, pos + 1, nums[pos]);
                path.pop_back();
            }
        }
    };
    bool CheckCase(vector<int> s, const vector<vector<int>>& expected, string& message) {
        Solution solver;
        vector<vector<int>> actual = solver.findSubsequences(s);
        sort(actual.begin(), actual.end());
        if (expected == actual) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{4, 6, 7, 7}, vector<vector<int>>{ { 4, 6 }, { 4,6,7 }, { 4,6,7,7 }, { 4,7 }, {4,7,7}, { 6, 7 }, { 6,7,7 }, { 7,7 }}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("491.findSubsequences", RunChecks);
}