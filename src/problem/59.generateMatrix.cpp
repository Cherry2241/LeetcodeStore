#include<vector>
#include <string>
#include<algorithm>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_59_generateMatrix{
    class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            int x = 1, i = 0, j = 0, z = 0, dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
            vector<vector<int>> r(n, vector<int>(n));
            while (x <= n * n)
            {
                r[i][j] = x;
                x++;
                if (i + dx[z] < 0 || i + dx[z] >= n || j + dy[z] < 0 || j + dy[z] >= n || r[i + dx[z]][j + dy[z]] != 0)
                {
                    z = (z + 1) % 4;
                }
                i = i + dx[z];
                j = j + dy[z];
            }
            return r;
        }
    };
    bool CheckCase(int n, const vector<vector<int>>& expected, string& message) {
        Solution solver;
        const vector<vector<int>> actual = solver.generateMatrix(n);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(3, vector< vector<int>> {{1,2, 3},{8,9,4}, {7,6,5}}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("59.generateMatrix", RunChecks);

}