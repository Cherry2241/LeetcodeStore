#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_263_isUgly {
    class Solution {
    public:
        bool isUgly(int n) {
            if (n <= 0) return false;
            while (n % 2 == 0) n = n / 2;
            while (n % 3 == 0) n = n / 3;
            while (n % 5 == 0) n = n / 5;
            if (n == 1) return true;
            else return false;
        }
    };
    bool CheckCase(int n, const bool& expected, string& message) {
        Solution solver;
        const bool actual = solver.isUgly(n);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(6, true, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("263.isUgly", RunChecks);
}