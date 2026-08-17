#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_541_reverseStr {
    class Solution {
    public:
        string reverseStr(string s, int k) {
            int len = s.size(), i, j;
            for (i = 0;i < len / (2 * k);i++)
            {
                for (j = 0;j < k / 2;j++)
                {
                    swap(s[i * 2 * k + j], s[i * 2 * k + k - j - 1]);
                }
            }
            int len1 = min(len - 2 * k * i, k);
            for (j = 0;j < len1 / 2;j++)
            {
                swap(s[i * 2 * k + j], s[i * 2 * k + len1 - j - 1]);
            }
            return s;
        }
    };
    bool CheckCase(string s,int k, const string& expected, string& message) {
        Solution solver;
        const string actual = solver.reverseStr(s,k);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase("abcdefg",2,"bacdfeg", message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("541.reverseStr", RunChecks);
}