#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_349_intersection {
    class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            int number[1001] = { 0 }, i, len1 = nums1.size(), len2 = nums2.size();
            vector<int> ans;
            for (i = 0;i < len1;i++)
            {
                if (number[nums1[i]] == 0) number[nums1[i]]++;
            }
            for (i = 0;i < len2;i++)
            {
                if (number[nums2[i]] == 1) number[nums2[i]]++;
            }
            for (i = 0;i <= 1000;i++)
            {
                if (number[i] == 2) ans.push_back(i);
            }
            return ans;
        }
    };
    bool CheckCase(vector<int> nums1,vector<int> nums2, const vector<int>& expected, string& message) {
        Solution solver;
        const vector<int> actual = solver.intersection(nums1,nums2);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{1, 2, 2, 1}, vector<int>{2,2}, vector<int>{2}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("349.intersection", RunChecks);
}