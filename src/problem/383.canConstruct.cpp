#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_383_canConstruct {
    class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            int len1 = ransomNote.size(), len2 = magazine.size(), i, m[26] = { 0 };
            for (i = 0;i < len2;i++)
            {
                m[magazine[i] - 'a']++;
            }
            for (i = 0;i < len1;i++)
            {
                if (m[ransomNote[i] - 'a'] == 0) return false;
                m[ransomNote[i] - 'a']--;
            }
            return true;
        }
    };
    bool CheckCase(string ransomNote, string magazine,const bool& expected, string& message) {
        Solution solver;
        int actual = solver.canConstruct(ransomNote, magazine);
        if (expected == actual) {
            return true;
        }
        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase("aa","aab",true, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("383.canConstruct", RunChecks);
}