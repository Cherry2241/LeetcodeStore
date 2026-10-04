#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_168_convertToTitle {
    class Solution {
    public:
        string convertToTitle(int columnNumber) {
            string s = "";
            int num;
            while (columnNumber > 0)
            {
                num = (columnNumber - 1) % 26;
                s += num + 'A';
                columnNumber = (columnNumber - num - 1) / 26;
            }
            reverse(s.begin(), s.end());
            return s;
        }
    };
    bool CheckCase(int columnNumber, const string& expected, string& message) {
        Solution solver;
        const  string actual = solver.convertToTitle(columnNumber);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(2147483647, "FXSHRXW", message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("168.convertToTitle", RunChecks);
}