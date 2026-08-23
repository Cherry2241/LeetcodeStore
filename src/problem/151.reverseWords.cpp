#include <string>
#include<iostream>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_151_reverseWords {
    class Solution {
    public:
        string reverseWords(string s) {
            int i, start, end;
            string ans = "", word;
            for (start = 0;s[start] == ' ';start++) {}
            for (end = s.size() - 1;s[end] == ' ';end--) {}
            i = start;
            while (i <= end)
            {
                word = "";
                for (;i <= end && s[i] != ' ';i++)
                {
                    word = word + s[i];
                }
                i++;
                if (word == "") continue;
                if (ans != "") ans = word + " " + ans;
                else ans = word;
            }
            return ans;
        }
    };
    bool CheckCase(string s, const string& expected, string& message) {
        Solution solver;
        const string actual = solver.reverseWords(s);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase("the sky is blue", "blue is sky the", message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("151.reverseWords", RunChecks);
}