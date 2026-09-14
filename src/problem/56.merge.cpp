#include<vector>
#include <string>
#include<algorithm>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_56_merge {
    class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end());
            int i, len = intervals.size(), start = intervals[0][0], end = intervals[0][1];
            vector<vector<int>> ans;
            for (i = 1;i < len;i++)
            {
                if (end >= intervals[i][0])
                {
                    end = max(intervals[i][1], end);
                }
                else
                {
                    ans.push_back({ start,end });
                    start = intervals[i][0];
                    end = intervals[i][1];
                }
            }
            ans.push_back({ start,end });
            return ans;
        }
    };
    bool CheckCase(vector<vector<int>> intervals, const vector<vector<int>>& expected, string& message) {
        Solution solver;
        const vector<vector<int>> actual = solver.merge(intervals);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(vector<vector<int>>{ {1, 3}, { 2, 6 }, { 8, 10 },{15, 18 }},vector<vector<int>>{ {1, 6}, { 8, 10 },{15, 18 }}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("56.merge", RunChecks);
}