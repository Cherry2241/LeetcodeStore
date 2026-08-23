#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_343_integerBreak {
    class Solution {
    public:
        int integerBreak(int n) {
            int dp[60] = { 0,1,1 }, i, j, a, b;
            for (i = 3;i <= n;i++)
            {
                for (j = 1;j <= i - 1;j++)
                {
                    a = max(dp[j], j);
                    b = max(dp[i - j], i - j);
                    dp[i] = max(dp[i], a*b);
                }
            }
            return dp[n];
        }
    };
    bool CheckCase(int s, const int& expected, string& message) {
        Solution solver;
        const int actual = solver.integerBreak(s);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(3, 2, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("343.integerBreak", RunChecks);
}