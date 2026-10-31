#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
#include<algorithm>
using namespace std;
namespace problem_47_permuteUnique {
    class Solution {
    public:
        vector<int> path;
        vector<vector<int>> ans;
        vector<int> vis;
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vis.resize(nums.size(), 0);
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
            for (i = 0;i < len;i++)
            {
                if (vis[i] == 1) continue;
                if (i != 0 && vis[i - 1] == 0 && nums[i] == nums[i - 1]) continue;
                vis[i] = 1;
                path.push_back(nums[i]);
                find(nums, pos + 1);
                vis[i] = 0;
                path.pop_back();
            }
        }
    };
    bool CheckCase(vector<int> s, const vector<vector<int>>& expected, string& message) {
        Solution solver;
        vector<vector<int>> actual = solver.permuteUnique(s);
        sort(actual.begin(), actual.end());
        if (expected == actual) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{2,2,1,1}, vector<vector<int>>{ { 1, 1, 2, 2 },{ 1, 2, 1, 2 }, { 1, 2, 2, 1 },  { 2, 1, 1, 2 }, { 2, 1, 2, 1 }, { 2, 2, 1, 1 }}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("47.permuteUnique", RunChecks);
}