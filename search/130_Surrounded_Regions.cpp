#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> directions = {-1, 0, 1, 0, -1};
    void solve(vector<vector<char>> &board)
    {

        int n = board.size(), m = board[0].size();
        vector<vector<bool>> flag(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) // brief 只从外则的0处外里dfs，记录可以走到的路径，最后进行统一地改变
        {
            cursion(board, flag, i, 0);
            cursion(board, flag, i, m - 1);
        }
        for (int i = 0; i < m; i++)
        {
            cursion(board, flag, 0, i);
            cursion(board, flag, n - 1, i);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!flag[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void cursion(vector<vector<char>> &board, vector<vector<bool>> &flag, int r, int c)
    {
        if (board[r][c] == 'O')
        {
            flag[r][c]=true;
        }
        else
        {
            return;
        }
        
        for (int k = 0; k < 4; k++)
        {
            int x = r + directions[k], y = c + directions[k + 1];
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !flag[x][y]) // flag 走过了就别走了
            {
                if (board[x][y] == 'O')
                {
                    flag[x][y] = true; //不用backtarack
                    cursion(board, flag, x, y);
                }
            }
        }
    }
};