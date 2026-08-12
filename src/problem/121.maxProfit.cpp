#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_121_maxProfit {
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int buy = prices[0], profit = 0, i;
            for (i = 1;i < prices.size();i++)
            {
                if (prices[i] < buy) buy = prices[i];
                profit = max(profit, prices[i] - buy);
            }
            return profit;
        }
    };
    bool CheckCase(vector<int> prices, const int expected, string& message) {
        Solution solver;
        const int actual = solver.maxProfit(prices);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{7, 1, 5, 3, 6, 4 }, 5, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }

    ProblemRegistrar registrar("121.Max Profit", RunChecks);
}
