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
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // 栈方法
        // int n = isConnected.size(), count = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (isConnected[i][j] == 1)
        //         {
        //             ++count;
        //             stack<pair<int, int>> sta;
        //             sta.push({i, j});
        //             isConnected[i][j] = 0;
        //             isConnected[j][i] = 0;

        //             while (!sta.empty())
        //             {
        //                 auto [r,c]=sta.top();
        //                 sta.pop();
        //                 for (int k = 0; k < n; k++)
        //                 {
        //                     if (isConnected[c][k]==1)
        //                     {
        //                         isConnected[c][k]=0;
        //                         isConnected[k][c]=0;
        //                         sta.push({c,k});
        //                     }
        //                 }
        //             }

        //         }
        //     }
        // }

        // return count;
        int n = isConnected.size(), count = 0;
        vector<bool> visited(n, false); //brief 创建了一个辅助函数
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                dfs(isConnected, i, visited);
                ++count;
            }
        }
        return count;
    }
    // 辅函数
    void dfs(vector<vector<int>> &friends, int i, vector<bool> &visited)
    {
        visited[i] = true; //对于一个点，走过了就不走了
        for (int k = 0; k < friends.size(); ++k)
        {
            if (friends[i][k] == 1 && !visited[k])
            {
                dfs(friends, k, visited);
            }
        }
    }
};

int main()
{
    vector<vector<int>> nums = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    Solution s;
    s.findCircleNum(nums);
}