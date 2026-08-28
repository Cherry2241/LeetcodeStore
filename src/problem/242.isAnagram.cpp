#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_242_isAnagram {
    class Solution {
    public:
        bool isAnagram(string s, string t) {
            int i, s1[26] = { 0 }, s2[26] = { 0 }, len1 = s.size(), len2 = t.size();
            if (len1 != len2) return false;
            for (i = 0;i < len1;i++)
            {
                s1[s[i] - 'a']++;
                s2[t[i] - 'a']++;
            }
            for (i = 0;i < 26;i++)
            {
                if (s1[i] != s2[i]) return false;
            }
            return true;
        }
    };
    bool CheckCase(string s, string t, const bool& expected, string& message) {
        Solution solver;
        const bool actual = solver.isAnagram(s, t);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase("anagram", "nagaram",true, message)) {
            return false;
        }
        if (!CheckCase("rat", "car",false, message)) {
            return false;
        }

        message = "2 cases passed";
        return true;
    }
    ProblemRegistrar registrar("242.isAnagram", RunChecks);
}