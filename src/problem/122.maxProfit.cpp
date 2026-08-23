#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_122_maxProfit {
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int buy = prices[0], profit = 0, i, len = prices.size();
            for (i = 1;i < len;i++)
            {
                if (prices[i] < buy) buy = prices[i];
                if (i < len - 1 && prices[i] < prices[i + 1]) continue;
                else
                {
                    profit = profit + prices[i] - buy;
                    buy = prices[i];
                }
            }
            return profit;
        }
    };
    bool CheckCase(vector<int> nums, const int& expected, string& message) {
        Solution solver;
        const int actual = solver.maxProfit(nums);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{7, 1, 5, 3, 6, 4}, 7, message)) {
            return false;
        }
        if (!CheckCase(vector<int>{1, 2, 3, 4, 5}, 4, message)) {
            return false;
        }
        
        message = "2 cases passed";
        return true;
    }
    ProblemRegistrar registrar("122.maxProfit", RunChecks);
}