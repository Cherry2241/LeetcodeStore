#include <string>
#include<algorithm>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_406_reconstructQueue{
    class Solution {
    public:
        static bool cmp(const vector<int>& a, const vector<int>& b)
        {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        }
        vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            int len = people.size(), i;
            vector<vector<int>> ans;
            sort(people.begin(), people.end(), cmp);
            for (const vector<int>& person : people)
            {
                ans.insert(ans.begin() + person[1], person);
            }
            return ans;
        }
    };
    bool CheckCase(vector<vector<int>> people, vector<vector<int>> expected, string& message) {
        Solution solver;
        vector<vector<int>> actual = solver.reconstructQueue(people);
        if (expected == actual) {
            return true;
        }
        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase({{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}}, {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("406.reconstructQueue", RunChecks);
}