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
    int m;
    int n;
    bool final;
    vector<int> direction = {-1, 0, 1, 0, -1};
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size(), n = board[0].size();
        vector<vector<bool>> flag(m, vector<bool>(n, false)); // brief 二维数组初始化
        int count = 0;

        for (int i = 0; !final && i < m; i++)
        {
            for (int j = 0; !final && j < n; j++)
            {
                if (board[i][j] == word[count])
                {
                    count++;
                    flag[i][j] = true;
                    backtracking(board, flag, word, count, i, j);
                    flag[i][j] = false;
                    count--;
                }
            }
        }

        return final ? true : false;
    }

    void backtracking(vector<vector<char>> &board, vector<vector<bool>> &flag, string &word, int &count,
                      int r, int c)
    {
        if (count == word.size())
        {
            final = true;
            return;
        }

        for (int k = 0; !final && k < 4; k++)
        {
            int x = r + direction[k], y = c + direction[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == word[count] && flag[x][y] == false)
            {
                count++;
                flag[x][y] = true;
                backtracking(board, flag, word, count, x, y);
                count--;
                flag[x][y] = false;
            }
        }
    }
};

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

    Solution s;
    s.exist(board,"ABCCED");
}