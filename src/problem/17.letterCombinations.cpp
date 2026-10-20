#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_17_letterCombinations {
    class Solution {
    public:
        string s = "";
        vector<string> ans;
        vector<string> phoneMap{ "abc", "def" ,"ghi","jkl", "mno", "pqrs","tuv" ,"wxyz" };
        vector<string> letterCombinations(string digits) {
            int len = digits.size();
            find(digits, 0);
            return ans;
        }
        void find(string digits, int pos)
        {
            if (pos == digits.size())
            {
                ans.push_back(s);
                return;
            }
            string letters = phoneMap[digits[pos] - '2'];
            for (char i : letters)
            {
                s.push_back(i);
                find(digits, pos + 1);
                s.pop_back();
            }
        }
    };
    bool CheckCase(string s, const vector<string>& expected, string& message) {
        Solution solver;
        const vector<string> actual = solver.letterCombinations(s);
        if (expected == actual) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase("23", vector<string>{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("17.letterCombinations", RunChecks);
}