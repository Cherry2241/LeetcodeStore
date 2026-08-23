#include <string>
#include<stack>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_20_isValid {
    class Solution {
    public:
        bool isValid(string s) {
            int i, len = s.size();
            stack<char> list;
            for (i = 0;i < len;i++)
            {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    list.push(s[i]);
                }
                else
                {
                    if (list.empty()) return false;
                    if (s[i] == ')' && list.top() != '(') return false;
                    if (s[i] == ']' && list.top() != '[') return false;
                    if (s[i] == '}' && list.top() != '{') return false;
                    list.pop();
                }
            }
            if (list.empty()) return true;
            else return false;
        }
    };
    bool CheckCase(string s,const bool& expected, string& message) {
        Solution solver;
        const bool actual = solver.isValid(s);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase("()[]{}", true, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("20.isValid", RunChecks);
}