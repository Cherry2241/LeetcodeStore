#include <string>
#include<algorithm>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_93_restoreIpAddresses {
    class Solution {
    public:
        vector<string> ans;
        vector<int> path;
        vector<string> restoreIpAddresses(string s) {
            find(s, 0, 0);
            return ans;
        }
        void find(string s, int pos, int t)
        {
            int num = 0, len = s.size(), i;
            if (len == pos && t == 4)
            {
                string ss = to_string(path[0]);
                for (i = 1;i < 4;i++) ss = ss + "." + to_string(path[i]);
                ans.push_back(ss);
                return;
            }
            if (len == pos || t == 4) return;
            if (s[pos] == '0')
            {
                path.push_back(0);
                find(s, pos + 1, t + 1);
                path.pop_back();
                return;
            }
            for (i = pos;i < pos + 3 && i < len;i++)
            {
                num = num * 10 + s[i] - '0';
                if (num >= 256) break;
                path.push_back(num);
                find(s, i + 1, t + 1);
                path.pop_back();
            }
        }
    };
    bool CheckCase(string s, const vector<string>& expected, string& message) {
        Solution solver;
        vector<string> actual = solver.restoreIpAddresses(s);
        sort(actual.begin(), actual.end());
        if (expected == actual) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase("101023", vector<string>{"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("93.restoreIpAddresses", RunChecks);
}