#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    int shortestBridge(vector<vector<int>> &grid)
    {
        // brief 广度优先搜索 常用来处理最短路径问题,一维一维的慢慢逼近
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;
        // dfs寻找第一个岛屿，并把1全部赋值为2
        bool flipped = false;
        for (int i = 0; i < m; ++i)
        {
            if (flipped)
                break;
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfs(points, grid, m, n, i, j);
                    flipped = true;
                    break;
                }
            }
        }

        // bfs寻找第二个岛屿，并把过程中经过的0赋值为2
        // brief bfs 将子节点推入到队列中，然后是先进先出，处理第一个节点，子节点推入队列，迭代
        // brief dfs 将子节点推入到栈中， 先进后出，处理子节点，将字节点的字节点推入栈中，迭代
        int x, y;
        int level = 0;
        while (!points.empty()) //brief 上面程序走完，队列中的第一维度的0，level=1，紧靠陆地的0
        {
            ++level;
            int n_points = points.size();
            while (n_points--) //遍历同一个维度的所有值
            {
                auto [r, c] = points.front(); //brief 复制第一个值
                points.pop(); //brief 移除第一个值
                for (int k = 0; k < 4; ++k)
                {
                    x = r + direction[k], y = c + direction[k + 1];
                    if (x >= 0 && y >= 0 && x < m && y < n)
                    {
                        if (grid[x][y] == 2)
                        {
                            continue;
                        }
                        if (grid[x][y] == 1)
                        {
                            return level;
                        }
                        points.push({x, y}); //还能再推进的都是0， 再推入下一个维度，
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }

    void dfs(queue<pair<int, int>> &points, vector<vector<int>> &grid, int m, int n, int i, int j)
    {
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2) //返回条件
        {
            return;
        }
        if (grid[i][j] == 0) //保存为0得点
        {
            points.push({i, j});
            return;
        }
        grid[i][j] = 2;
        dfs(points, grid, m, n, i - 1, j); //各个方向dfs
        dfs(points, grid, m, n, i + 1, j);
        dfs(points, grid, m, n, i, j - 1);
        dfs(points, grid, m, n, i, j + 1);
    }
};