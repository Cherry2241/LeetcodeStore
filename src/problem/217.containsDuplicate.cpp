#include<map>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_217_containsDuplicate {
    class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            map<int, int> m;
            int len = nums.size(), i;
            for (i = 0;i < len;i++)
            {
                auto it = m.find(nums[i]);
                if (it != m.end()) return true;
                m.emplace(nums[i], 1);
            }
            return false;
        }
    };
    bool CheckCase(vector<int>& nums, const bool& expected, string& message) {
        Solution solver;
        const bool actual = solver.containsDuplicate(nums);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{1, 2, 3, 1}, true, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("217.containsDuplicate", RunChecks);
}