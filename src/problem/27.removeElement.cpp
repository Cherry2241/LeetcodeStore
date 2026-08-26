#include <string>
#include<vector>
#include<algorithm>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_27_removeElement {
    class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int len = nums.size(), pos1 = 0, pos2 = 0;
            while (pos2 < len)
            {
                if (nums[pos2] == val)
                {
                    pos2++;
                }
                else
                {
                    nums[pos1] = nums[pos2];
                    pos1++;
                    pos2++;
                }
            }
            return pos1;
        }
    };
    bool CheckCase(vector<int> nums,int val, const int& expected,const vector<int>& exNums, string& message) {
        Solution solver;
        const int actual = solver.removeElement(nums,val);
        message = "CheckCase failed";
        sort(nums.begin(), nums.begin() + exNums.size());
        for (int i = 0;i < exNums.size();i++)
        {
            if (nums[i] != exNums[i]) return false;
        }
        if (actual == expected) {
            return true;
        }
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{3, 2, 2, 3}, 3, 2, vector<int>{2, 2}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("27.removeElement", RunChecks);
}