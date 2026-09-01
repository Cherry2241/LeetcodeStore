#include<vector>
#include<set>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_202_isHappy {
    class Solution {
    public:
        bool isHappy(int n) {
            set<int> s;
            while (true)
            {
                int next = 0;
                while (n > 0)
                {
                    next = next + (n % 10) * (n % 10);
                    n = n / 10;
                }
                if (next == 1)
                {
                    return true;
                }
                n = next;
                auto it = s.find(n);
                if (it != s.end()) return false;
                else s.insert(n);
            }
        }
    };
    bool CheckCase(int n, const bool& expected, string& message) {
        Solution solver;
        const bool actual = solver.isHappy(n);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(19, true, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("202.isHappy", RunChecks);
}