#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_150_evalRPN {
    class Solution {
    public:
        int toNum(string s)
        {
            int i = 0, num = 0, len = s.size(), flag = 1;
            if (s[0] == '-')
            {
                flag = -1;
                i = i + 1;
            }
            for (;i < len;i++)
            {
                num = num * 10 + s[i] - '0';
            }
            return num * flag;
        }
        int evalRPN(vector<string>& tokens) {
            int num, sum = 0, i, len = tokens.size(), top = -1;
            vector<int> s(len);
            for (i = 0;i < len;i++)
            {
                if (tokens[i] == "+")
                {
                    s[top - 1] = s[top] + s[top - 1];
                    s[top] = 0;
                    top--;
                }
                else if (tokens[i] == "-")
                {
                    s[top - 1] = s[top - 1] - s[top];
                    s[top] = 0;
                    top--;
                }
                else if (tokens[i] == "*")
                {
                    s[top - 1] = s[top - 1] * s[top];
                    s[top] = 0;
                    top--;
                }
                else if (tokens[i] == "/")
                {
                    s[top - 1] = s[top - 1] / s[top];
                    s[top] = 0;
                    top--;
                }
                else s[++top] = (toNum(tokens[i]));
            }
            return s[0];
        }
    };
    bool CheckCase(vector<string> s, const int& expected, string& message) {
        Solution solver;
        int actual = solver.evalRPN(s);
        if (expected == actual) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<string>{"2", "1", "+", "3", "*"}, 9, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("150.evalRPN", RunChecks);
}