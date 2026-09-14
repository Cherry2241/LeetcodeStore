#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_67_addBinary {
    class Solution {
    public:
        string addBinary(string a, string b) {
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            string ans;
            int len1 = a.size(), len2 = b.size(), len = max(len1, len2), i, carry = 0;
            for (i = 0;i < len;i++)
            {
                if (i < len1 && a[i] == '1') carry++;
                if (i < len2 && b[i] == '1') carry++;
                if (carry >= 2)
                {
                    ans.push_back(carry - 2 + '0');
                    carry = 1;
                }
                else
                {
                    ans.push_back(carry + '0');
                    carry = 0;
                }
            }
            if (carry == 1) ans.push_back('1');
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
    bool CheckCase(string a, string b, const string& expected, string& message) {
        Solution solver;
        const string actual = solver.addBinary(a, b);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase("1", "11", "100", message)) {
            return false;
        }
        if (!CheckCase("1010", "1011", "10101", message)){
            return false;
        }
        message = "2 cases passed";
        return true;
    }
    ProblemRegistrar registrar("67.addBinary", RunChecks);
}