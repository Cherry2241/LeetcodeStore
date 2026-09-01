#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_860_lemonadeChange {
    class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int num5 = 0, num10 = 0, i, len = bills.size();
            for (i = 0;i < len;i++)
            {
                int change = bills[i] - 5, b;
                if (num10 > 0 && change >= 10)
                {
                    num10--;
                    change = change - 10;
                }
                if (num5 > 0 && change >= 5)
                {
                    b = min(change / 5, num5);
                    num5 = num5 - b;
                    change = change - 5 * b;
                }
                if (change > 0) return false;
                if (bills[i] == 5) num5++;
                if (bills[i] == 10) num10++;
            }
            return true;
        }
    };
    bool CheckCase(vector<int> bills, const int& expected, string& message) {
        Solution solver;
        const int actual = solver.lemonadeChange(bills);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{5, 5, 5, 10, 20},true, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("860.lemonadeChange", RunChecks);
}