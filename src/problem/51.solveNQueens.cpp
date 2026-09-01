#include<vector>
#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_51_solveNQueens {
    class Solution {
    public:
        vector<vector<string>> ans;
        vector<vector<string>> solveNQueens(int n) {
            vector<string> board(n, string(n, '.'));
            find(board, 0, n);
            return ans;
        }
        void find(vector<string>& board, int row, int n)
        {
            if (row == n)
            {
                ans.push_back(board);
                return;
            }
            for (int i = 0;i < n;i++)
            {
                if (ifPut(board, row, i))
                {
                    board[row][i] = 'Q';
                    find(board, row + 1, n);
                    board[row][i] = '.';
                }
            }
        }
        bool ifPut(vector<string> board, int row, int col)
        {
            int n = board[0].size();
            for (int i = 0;i < row;i++)
            {
                for (int j = 0;j < n;j++)
                {
                    if (board[i][j] == 'Q')
                    {
                        if (col == j) return false;
                        if (j + row - i < n && j + row - i == col) return false;
                        if (j - row + i >= 0 && j - row + i == col) return false;
                        break;
                    }
                }
            }
            return true;
        }
    };
    bool CheckCase(int n, const vector<vector<string>>& expected, string& message) {
        Solution solver;
        const vector<vector<string>> actual = solver.solveNQueens(n);

        if (actual == expected) {
            return true;
        }

        message = "CheckCase failed";
        return false;
    }

    bool RunChecks(std::string& message) {
        if (!CheckCase(4, vector<vector<string>>{{".Q..", "...Q", "Q...", "..Q."}, { "..Q.","Q...","...Q",".Q.." }}, message)) {
            return false;
        }

        message = "1 cases passed";
        return true;
    }
    ProblemRegistrar registrar("51.solveNQueens", RunChecks);
}