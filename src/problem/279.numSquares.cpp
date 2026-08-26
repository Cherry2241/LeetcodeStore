#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_279_numSquares {
    class Solution {
    public:
        int numSquares(int n) {
            vector<int> ans(n + 1, 10000);
            int i, k;
            ans[0] = 0;
            ans[1] = 1;
            for (i = 1;i <= n;i++)
            {
                for (k = 1;k * k <= i;k++)
                {
                    ans[i] = min(ans[i], ans[i - k * k] + 1);
                }
            }
            return ans[n];
        }
    };
    bool CheckCase(int n, const int& expected, string& message) {
        Solution solver;
        const int actual = solver.numSquares(n);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(12, 3, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("279.numSquares", RunChecks);
}