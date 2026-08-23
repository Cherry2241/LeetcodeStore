#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_1047_removeDuplicates {
    class Solution {
    public:
        string removeDuplicates(string s) {
            int i, len = s.size();
            string ans;
            for (i = 0;i < len;i++)
            {
                if (!ans.empty() && ans.back() == s[i])  ans.pop_back();
                else ans.push_back(s[i]);
            }
            return ans;
        }
    };
    bool CheckCase(string s, const string& expected, string& message) {
        Solution solver;
        const string actual = solver.removeDuplicates(s);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase("abbaca", "ca", message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("1047.removeDuplicates", RunChecks);
}