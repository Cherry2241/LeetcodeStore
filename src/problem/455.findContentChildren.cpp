#include <string>
#include<vector>
#include<algorithm>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_455_findContentChildren {
    class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            int len1 = g.size(), len2 = s.size(), i = 0, j = 0, ans = 0;
            while (i < len1 && j < len2)
            {
                if (g[i] <= s[j])
                {
                    ans++;
                    i++;
                }
                j++;
            }
            return ans;
        }
    };
    bool CheckCase(vector<int> g, vector<int> s, const int& expected, string& message) {
        Solution solver;
        const int actual = solver.findContentChildren(g,s);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{1, 2, 3}, vector<int>{1, 1}, 1, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("455.findContentChildren", RunChecks);
}