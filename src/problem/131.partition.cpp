#include <string>
#include<algorithm>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_131_partition {
    class Solution {
    public:
        vector<string> path;
        vector<vector<string>> ans;
        vector<vector<string>> partition(string s) {
            find(s, 0);
            return ans;
        }
        void find(string& s, int pos)
        {
            int len = s.size(), i;
            string ss = "";
            if (pos == len)
            {
                ans.push_back(path);
                return;
            }
            for (i = pos;i < len;i++)
            {
                ss = ss + s[i];
                if (ifReverse(ss))
                {
                    path.push_back(s.substr(pos, i - pos + 1));
                    find(s, i + 1);
                    path.pop_back();
                }
            }
        }
        bool ifReverse(string& s)
        {
            int len = s.size(), i;
            for (i = 0;i < len / 2;i++)
            {
                if (s[i] != s[len - i - 1]) return false;
            }
            return true;
        }
    };
    bool CheckCase(string s, const vector<vector<string>>& expected, string& message) {
        Solution solver;
        vector<vector<string>> actual = solver.partition(s);
        sort(actual.begin(), actual.end());
        if (expected == actual) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase("aab", vector<vector<string>>{{"a", "a", "b"}, {"aa", "b"}}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("131.partition", RunChecks);
}