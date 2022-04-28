#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        //只要临近的 三个方向 就可以确定能否 构成正方形
        // dp二维数组记录边长，不用面积，面积不好弄，不用其他三个方向加在一起，可以直接得到
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), max_side = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1; //brief 状态转移方程 比较或者加
                    //brief 直接 三个方向最小值加一
                }
                max_side = max(max_side, dp[i][j]);
            }
        }
        return max_side * max_side;
    }
};