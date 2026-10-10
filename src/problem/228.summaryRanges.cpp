#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_228_containsNearbyDuplicate {
    class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            int i = 0, len = nums.size();
            vector<string> ans;
            while (i < len)
            {
                int start = nums[i], end;
                while (i + 1 < len && nums[i] + 1 == nums[i + 1])
                {
                    ++i;
                }
                end = nums[min(i, len)];
                if (start == end) ans.push_back(to_string(start));
                else ans.push_back(to_string(start) + "->" + to_string(end));
                i++;
            }
            return ans;
        }
    };
    bool CheckCase(vector<int>& nums ,const vector<string>& expected, string& message) {
        Solution solver;
        const vector<string> actual = solver.summaryRanges(nums);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{0, 1, 2, 4, 5, 7 },vector<string>{"0->2", "4->5", "7"}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("228.summaryRanges", RunChecks);
}