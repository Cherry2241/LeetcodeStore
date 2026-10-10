#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_171_titleToNumber {
    class Solution {
    public:
        int titleToNumber(string columnTitle) {
            int len = columnTitle.size(), i, ans = 0;
            for (i = 0;i < len;i++)
            {
                int num = columnTitle[i] - 'A' + 1;
                ans = ans * 26 + num;
            }
            return ans;
        }
    };
    bool CheckCase(string columnTitle, const int& expected, string& message) {
        Solution solver;
        const  int actual = solver.titleToNumber(columnTitle);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase("ZY",701, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("171.titleToNumber", RunChecks);
}