#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_216_combinationSum3 {
    class Solution {
    public:
        vector<int> nums;
        vector<vector<int>> ans;
        vector<vector<int>> combinationSum3(int k, int n) {
            find(k, n, 0);
            return ans;
        }
        void find(int k, int n, int minNum)
        {
            if (n < 0) return;
            if (k == 0)
            {
                if (n == 0) ans.push_back(nums);
                return;
            }
            int i;
            for (i = minNum + 1;i <= 9;i++)
            {
                nums.push_back(i);
                find(k - 1, n - i, i);
                nums.pop_back();
            }
        }
    };
    bool CheckCase(int n, int k, const vector<vector<int>>& expected, string& message) {
        Solution solver;
        const vector<vector<int>> actual = solver.combinationSum3(n, k);

        if (expected == actual) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(3, 7, vector<vector<int>>{vector<int>{1, 2,4}}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("216.combinationSum3", RunChecks);
}