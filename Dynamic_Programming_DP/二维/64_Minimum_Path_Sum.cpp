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
    int minPathSum(vector<vector<int>> &grid)
    {
        //建立一个二维表，表中每一项保存到该位置的 最小值

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    distance[i][j] = min(distance[i - 1][j] + grid[i][j], distance[i][j - 1] + grid[i][j]);
                }
                else if (i - 1 >= 0)
                {
                    distance[i][j] = distance[i - 1][j] + grid[i][j];
                }
                else if (j - 1 >= 0)
                {
                    distance[i][j] = distance[i][j - 1] + grid[i][j];
                }
                else
                {
                    distance[i][j] = grid[i][j];
                }
            }
        }

        return distance[m - 1][n - 1];
    }
};