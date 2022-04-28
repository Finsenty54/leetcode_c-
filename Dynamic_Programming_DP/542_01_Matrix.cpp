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
    vector<int> directions{-1, 0, 1, 0, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        //深度优先遍历，得到的信息都保存起来，剪枝条
        //我们从左上到右下进行一次动态搜索，再从右下到左上进行一次动态搜索。两次动态搜索即可完成四个方向上的查找
        //求最小距离，应该是广度优先，用队列，一层一层下去

        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT32_MAX-1)); //最大值宏
        // vector<vector<int>> tmp_dis(n, vector<int>(m, -1));

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         if (mat[i][j])
        //         {
        //             dis[i][j] = 0;
        //         }
        //     }
        // }

        // dfs();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (mat[i][j] == 0)
                {
                    dis[i][j] = 0;
                }
                else
                {
                    //如果都不符合就是没有,从两个方向取，自己保存当前的最小值
                    if (j > 0)
                    {
                        dis[i][j] = min(dis[i][j], dis[i][j - 1] + 1);
                    }
                    if (i > 0)
                    {
                        dis[i][j] = min(dis[i][j], dis[i - 1][j] + 1);
                    }
                }
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                if (mat[i][j] != 0)
                {
                    //从两个反向取
                    if (j < m - 1) 
                    {
                        dis[i][j] = min(dis[i][j], dis[i][j + 1] + 1);
                    }
                    if (i < n - 1)
                    {
                        dis[i][j] = min(dis[i][j], dis[i + 1][j] + 1);
                    }
                }
            }
        }

        return dis;
    }

    // void dfs(vector<vector<int>> &dis,vector<vector<int>> &tmp_dis, vector<vector<int>> &mat, int r, int c)
    // {
    //     if (mat[r][c] == 0)
    //     {
    //         return;
    //     }

    //     for (int i = 0; i < 4; i++)
    //     {
    //         int x = r + directions[i], y = c + directions[i + 1];
    //         if (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size())
    //         {
    //             if (dis[x][y] == -1)
    //             {
    //                 tmp_dis[x]
    //                 dfs(dis,tmp_dis, mat, x, y);
    //             }
    //             else
    //             {
    //                 /* code */
    //             }

    //         }
    //     }
    // }
};

int main()
{
    vector<vector<int>> mat={{1,1,1},{1,1,0},{0,0,0}};
    Solution S;
    S.updateMatrix(mat);
}