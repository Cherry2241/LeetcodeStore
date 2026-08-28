#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_1002_commonChars {
    class Solution {
    public:
        vector<string> commonChars(vector<string>& words) {
            vector<string> ans;
            int sum[26], len = words.size(), i, j;
            vector<int> common(26, INT_MAX);
            for (i = 0;i < len;i++)
            {
                memset(sum, 0, sizeof(sum));
                for (j = 0;j < words[i].size();j++) sum[words[i][j] - 'a']++;
                for (j = 0;j < 26;j++) common[j] = min(common[j], sum[j]);
            }
            for (i = 0;i < 26;i++)
            {
                for (j = 0;j < common[i];j++)
                {
                    string s(1, 'a' + i);
                    ans.push_back(s);
                }
            }
            return ans;
        }
    };
    bool CheckCase(vector<string> s, const vector<string>& expected, string& message) {
        Solution solver;
        const vector<string> actual = solver.commonChars(s);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<string>{"bella", "label", "roller"},vector<string>{"e", "l", "l"}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("1002.commonChars", RunChecks);
}