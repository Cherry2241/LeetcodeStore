#include<map>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_205_isIsomorphic {
    class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            map<char, char> st, ts;
            int len = s.size(), i;
            for (i = 0;i < len;i++)
            {
                auto it1 = st.find(s[i]);
                auto it2 = ts.find(t[i]);
                if (it1 != st.end() && it1->second != t[i]) return false;
                if (it2 != ts.end() && it2->second != s[i]) return false;
                st.emplace(s[i], t[i]);
                ts.emplace(t[i], s[i]);
            }
            return true;
        }
    };
    bool CheckCase(string s,string t, const bool& expected, string& message) {
        Solution solver;
        const bool actual = solver.isIsomorphic(s,t);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase("egg","add", true, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("205.isIsomorphic", RunChecks);
}