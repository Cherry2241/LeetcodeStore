#include<set>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_219_containsNearbyDuplicate {
    class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            int i, len = nums.size();
            set<int> s;
            for (i = 0;i < len;i++)
            {
                if (i > k) s.erase(nums[i - k - 1]);
                if (s.count(nums[i])) return true;
                s.emplace(nums[i]);
            }
            return false;
        }
    };
    bool CheckCase(vector<int>& nums,int k, const bool& expected, string& message) {
        Solution solver;
        const bool actual = solver.containsNearbyDuplicate(nums,k);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{1, 2, 3, 1, 2, 3 },2, false, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("219.containsNearbyDuplicate", RunChecks);
}