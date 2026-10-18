#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_77_combine {
    class Solution {
    public:
        vector<vector<int>> ans;
        vector<vector<int>> combine(int n, int k) {
			vector<int> nums;
            find(n, k, 0, nums);
            return ans;
        }
        void find(int n, int k, int minNum, vector<int>& nums)
        {
            if (k == 0)
            {
                ans.push_back(nums);
                return;
            }
            int i;
            for (i = minNum + 1;i <= n - k + 1;i++)
            {
                nums.push_back(i);
                find(n, k - 1, i, nums);
                nums.pop_back();
            }
        }
    };
    bool CheckCase(int n,int k, const vector<vector<int>>& expected, string& message) {
        Solution solver;
        const vector<vector<int>> actual = solver.combine(n,k);

        if (expected==actual) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(4,2,vector<vector<int>>{vector<int>{1,2},vector<int>{1,3},vector<int>{1,4},vector<int>{2,3},vector<int>{2,4},vector<int>{3,4}}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("77.combine", RunChecks);
}