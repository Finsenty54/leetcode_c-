#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<bool> row_flag(n, false), column_flag(n, false), left_flag(2 * n - 1, false), right_flag(2 * n - 1, false);
        // vector<vector<bool>> print_flag(n, vector<bool>(n, false)); //brief 都建了一个数组，不如直接建 '.'
        vector<int> help_right(n);
        // generate(help_right.begin(), help_right.end(), [=] { // brief generate函数
        //     static int i = n;
        //     return --i;
        // });
        vector<string> board(n,string(n,'.'));
        int count = 0;
        vector<vector<string>> ans;
        backtracking(column_flag, left_flag, right_flag, board, n, ans, 0);

        return ans;
    }

    void backtracking(vector<bool> &column_flag, vector<bool> &left_flag, vector<bool> &right_flag,
                      vector<string> &board, int &n, vector<vector<string>> &ans,int row)
    {
        if (row == n)
        {
            // vector<string> tmp;
            // for (int i = 0; i < n; i++)
            // {
            //     string t;
            //     for (int j = 0; j < n; j++)
            //     {
            //         if (print_flag[i][j])
            //             t.push_back('Q');
            //         else
            //             t.push_back('.');
            //     }
            //     tmp.push_back(t);
            // }
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if ( !column_flag[j] && !left_flag[row + j] && !right_flag[n-row+j-1])
            {
                // row_flag[i] = true;
                column_flag[j] = true;
                left_flag[row + j] = true;
                right_flag[n-row+j-1] = true;
                // print_flag[i][j] = true;
                // ++count;
                board[row][j]='Q';
                backtracking(column_flag, left_flag, right_flag,board, n, ans, row + 1);
                // row_flag[i] = false;
                board[row][j]='.';
                column_flag[j] = false;
                left_flag[row + j] = false;
                right_flag[n-row+j-1] = false;
                // print_flag[i][j] = false;
                // --count;
            }
        }
    }
};

int main()
{
    Solution s;
    s.solveNQueens(1);
}