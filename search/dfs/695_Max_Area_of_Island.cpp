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
    vector<int> direction{-1, 0, 1, 0, -1};
    int local_area;
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        // brief 使用栈的方法
        int m = grid.size(), n = m ? grid[0].size() : 0, area = 0, x, y;
        // for (int i = 0; i < m; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         if (grid[i][j])
        //         {
        //             local_area = 1;
        //             grid[i][j] = 0; //搜索过置0
        //             stack<pair<int, int>> island;
        //             island.push({i, j});
        //             while (!island.empty()) //brief 相当于直接对子节点进行搜索
        //             {
        //                 auto [r, c] = island.top(); //brief c++17标准，返回多个值 （&& 将亡值）
        //                 island.pop();
        //                 for (int k = 0; k < 4; ++k)
        //                 {
        //                     x = r + direction[k], y = c + direction[k + 1]; //brief 遍历所有方向
        //                     if (x >= 0 && x < m &&
        //                         y >= 0 && y < n && grid[x][y] == 1) //brief 有一个地方是，压入栈，有对该地方进行搜索 = DFS
        //                     {
        //                         grid[x][y] = 0; //搜索过置0
        //                         ++local_area;
        //                         island.push({x, y});
        //                     }
        //                 }
        //             }
        //             area = max(area, local_area);
        //         }
        //     }
        // }
        // return area;

        // brief 使用递归的方法
        if (grid.empty() || grid[0].empty())
            return 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    local_area = 1;
                    recursion(grid, i, j);
                    area = max(area, local_area);
                }
            }
        }
        return area;
    }

    void recursion(vector<vector<int>> &grid, int row, int column)
    {
        grid[row][column] = 0;
        for (int k = 0; k < 4; k++)
        {
            int r = row + direction[k], c = column + direction[k + 1];
            if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 1)
            {
                local_area++;
                recursion(grid, r, c);
            }
        }
    }
};