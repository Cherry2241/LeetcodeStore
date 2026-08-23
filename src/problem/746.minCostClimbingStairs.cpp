#include <string>
#include<vector>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_746_minCostClimbingStairs {
    class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int len = cost.size(), i, minCost[1001] = { 0 };
            for (i = 2;i <= len;i++)
            {
                minCost[i] = min(minCost[i - 1] + cost[i - 1], minCost[i - 2] + cost[i - 2]);
            }
            return minCost[len];
        }
    };
    bool CheckCase(vector<int> s, const int& expected, string& message) {
        Solution solver;
        const int actual = solver.minCostClimbingStairs(s);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{1,100,1,1,1,100,1,1,100,1}, 6, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("746.minCostClimbingStairs", RunChecks);
}