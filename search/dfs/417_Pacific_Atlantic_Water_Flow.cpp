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
    vector<int> direction1 = {-1, 0, 0, -1, 0, 1, 1, 0};
    vector<int> direction = {-1, 0, 1, 0, -1};
    bool pacific = false; //辅助变量设小了
    bool atantic = false;
    int n = 0;
    int m = 0;
    // vector<int> direction2 = {1, 0, -1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        if (heights.empty() || heights[0].empty())
        {
            return {};
        }
        vector<vector<int>> ans;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false)); //分成两部分
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) //brief 因此我们可以反过来想，从两个大洋开始向上流，这样我们只需要对矩形四条边进行搜索。
        { 
            dfs(heights, can_reach_p, i, 0);
            dfs(heights, can_reach_a, i, n - 1);
        }
        for (int i = 0; i < n; ++i)
        {
            dfs(heights, can_reach_p, 0, i);
            dfs(heights, can_reach_a, m - 1, i);
        }
        for (int i = 0; i < m; i++) //brief 最后遍历一遍矩阵
        {
            for (int j = 0; j < n; ++j)
            {
                if (can_reach_p[i][j] && can_reach_a[i][j])
                {
                    ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }
    // 辅函数
    void dfs(const vector<vector<int>> &heights, vector<vector<bool>> &can_reach,
             int r, int c)
    {
        if (can_reach[r][c]) //分成两部分，直接返回，减少时间
        {
            return;
        }
        can_reach[r][c] = true; //brief 从边向上流，能到哪里是哪里
        int x, y;
        for (int i = 0; i < 4; ++i)
        {
            x = r + direction[i], y = c + direction[i + 1];
            if (x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size() &&
                heights[r][c] <= heights[x][y])
            {
                dfs(heights, can_reach, x, y);
            }
        }
    }
    //     vector<vector<int>> results;
    //     n = heights.size(), m = heights[0].size();
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < m; j++)
    //         {
    //             if (i == 0 || j == 0)
    //             {
    //                 pacific = true;
    //             }
    //             if (i == (n - 1) || j == (m - 1))
    //             {
    //                 atantic = true;
    //             }

    //             // brief 如果满足条件，就再次递归下去
    //             for (int k = 0; k < 8; k += 2)
    //             {
    //                 if (i + direction1[k] >= 0 && i + direction1[k] < n && j + direction1[k + 1] >= 0 && j + direction1[k + 1] < m && heights[i + direction1[k]][j + direction1[k + 1]] <= heights[i][j])
    //                 {
    //                     if (k < 4 && !pacific)
    //                         ocean(heights, i + direction1[k], j + direction1[k + 1]);

    //                     if (k > 3 && !atantic)
    //                         ocean(heights, i + direction1[k], j + direction1[k + 1]);
    //                 }
    //             }
    //             if (pacific && atantic)
    //             {
    //                 results.push_back({i, j});
    //             }
    //             pacific = false;
    //             atantic = false;
    //         }
    //     }
    //     return results;
    // }

    // void ocean(vector<vector<int>> &heights, int r, int c)
    // {
    //     if (pacific && atantic)
    //     {
    //         return;
    //     }

    //     if (r == 0 || c == 0)
    //     {
    //         pacific = true;
    //     }
    //     if (r == (n - 1) || c == (m - 1))
    //     {
    //         atantic = true;
    //     }

    //     for (int k = 0; k < 8; k += 2)
    //     {
    //         if (r + direction1[k] >= 0 && r + direction1[k] < n && c + direction1[k + 1] >= 0 && c + direction1[k + 1] < m && heights[r + direction1[k]][c + direction1[k + 1]] <= heights[r][c])
    //         {
    //             if (k < 4 && !pacific)
    //             {
    //                 ocean(heights, r + direction1[k], c + direction1[k + 1]);
    //             }
    //             if (k > 3 && !atantic)
    //             {
    //                 ocean(heights, r + direction1[k], c + direction1[k + 1]);
    //             }
    //         }
    //     }
    // }
};

int main()
{
    vector<vector<int>> nums = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    Solution s;
    s.pacificAtlantic(nums);
}