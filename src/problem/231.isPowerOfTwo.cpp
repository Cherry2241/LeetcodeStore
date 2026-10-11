#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_231_isPowerOfTwo {
    class Solution {
    public:
        bool isPowerOfTwo(int n) {
            return n > 0 && (n & (n - 1)) == 0;
        }
    };
    bool CheckCase(int n, const bool& expected, string& message) {
        Solution solver;
        const bool actual = solver.isPowerOfTwo(n);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(16, true, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("231.isPowerOfTwo", RunChecks);
}