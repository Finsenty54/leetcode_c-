#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        //对于分割类型题，动态规划的状态转移方程通常并不依赖相邻的位置，而是依赖于满足分割条件的位置
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1); //只要找到状态转移方程就行了
            }
        }
        return dp[n];

        // bfs 也可以解，每一层减去1，4，9...，那一层减为0了，就是最小数
        // queue<int> q;
        // q.push(n);
        // int depth = 0;
        // while (!q.empty())
        // {
        //     int q_size = q.size();
        //     while (q_size)
        //     {
        //         q_size--;
        //         int num = q.front();
        //         q.pop();
        //         for (int i = 1; i * i <= num; i++)
        //         {
        //             int sub = num - i * i;
        //             if (sub == 0)
        //                 return depth + 1;
        //             q.push(sub);
        //         }
        //     }
        //     depth++;
        // }
        // return n;
    }
};

int main()
{
    Solution S;
    S.numSquares(12);
}