#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_88_mergeSortedArray {
    class Solution {
    public:
        vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            vector<int> s(m + n);
            int h1 = 0, h2 = 0, h3 = 0;
            while (h1 < m && h2 < n)
            {
                if (nums1[h1] <= nums2[h2])
                {
                    s[h3++] = nums1[h1++];
                }
                else
                {
                    s[h3++] = nums2[h2++];
                }
            }
            while (h1 < m) s[h3++] = nums1[h1++];
            while (h2 < n) s[h3++] = nums2[h2++];
            for (h1 = 0;h1 < m + n;h1++)
            {
                nums1[h1] = s[h1];
            }
            return nums1;
        }
    };
    bool CheckCase(vector<int> num1,int m,vector<int> num2,int n, const vector<int>& expected, string& message) {
        Solution solver;
        const std::vector<int> actual = solver.merge(num1, m, num2, n);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<int>{1, 2, 3, 0, 0, 0}, 3, vector<int>{2, 5, 6}, 3, vector<int>{1, 2, 2, 3, 5, 6}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }

    ProblemRegistrar registrar("88.Merge Sorted Array", RunChecks);
}