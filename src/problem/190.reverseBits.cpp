#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_190_reverseBits {
    class Solution {
    public:
        int reverseBits(int n) {
            int ans = 0;
            for (int i = 0;i < 32;i++)
            {
                int num = n % 2;
                ans = ans * 2 + num;
                n = n / 2;
            }
            return ans;
        }
    };
    bool CheckCase(int n, const int& expected, string& message) {
        Solution solver;
        const  int actual = solver.reverseBits(n);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(43261596, 964176192, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("190.reverseBits", RunChecks);
}