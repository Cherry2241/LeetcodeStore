#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_134_canCompleteCircuit {
    class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int pos, i, len = gas.size();
            for (i = 0;i < len;)
            {
                int sum = 0, cosume = 0, cnt;
                for (cnt = 0;cnt < len;cnt++)
                {
                    pos = (cnt + i) % len;
                    sum = sum + gas[pos];
                    cosume = cosume + cost[pos];
                    if (sum < cosume) break;
                }
                if (cnt == len)
                {
                    return i;
                }
                i = cnt + i + 1;
            }
            return -1;
        }
    };
    bool CheckCase(vector<int> gas,vector<int>cost,const int& expected, string& message) {
        Solution solver;
        const int actual = solver.canCompleteCircuit(gas,cost);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{1, 2, 3, 4, 5},vector<int>{3, 4, 5, 1, 2},3, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("134.canCompleteCircuit", RunChecks);
}