#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_119_getRow {
    class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            int num = 1, i;
            vector<int> ans;
            for (i = 0;i <= rowIndex;i++)
            {
                ans.push_back(num);
                num = (long long)num * (long long)(rowIndex - i) / (i + 1);
            }
            return ans;
        }
    };
    bool CheckCase(int rowIndex, const vector<int>& expected, string& message) {
        Solution solver;
        const vector<int> actual = solver.getRow(rowIndex);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(3,vector<int>{1,3,3,1}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("119.getRow", RunChecks);
}