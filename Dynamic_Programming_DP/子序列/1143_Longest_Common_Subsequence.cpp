#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        /**
         * brief 对于子序列问题，第二种动态规划方法是，定义一个 dp 数组，其中 dp[i] 表示到位置 i 为止
            的子序列的性质，并不必须以 i 结尾。这样 dp 数组的最后一位结果即为题目所求，不需要再对每
            个位置进行统计。
         *
         * date 2022-05-05
         */

        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); //二维数组 完全统计 i->j的最长公共子序列
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];

        // brief 下面是第一种 记录以i结尾的子序列的性质
        // int size_t1 = text1.size();
        // vector<pair<int, int>> dp(size_t1, {0, -1});
        // if (text1[0]==text2[0])
        // {
        //     dp[0]={1,0};
        // }

        // int max_num = 0;
        // for (int i = 0; i < size_t1; i++)
        // {
        //     for (int j = 0; j < text2.size(); j++)
        //     {
        //         if (text1[i] == text2[j])
        //         {
        //             for (int k = 0; k < i; k++)
        //             {
        //                 if (j > dp[k].second)
        //                 {
        //                     dp[i] = {max(dp[i].first, dp[k].first + 1), j};
        //                 }
        //             }
        //             break;
        //         }
        //     }
        //     if (dp[i].first > max_num)
        //         max_num = dp[i].first;
        // }

        // return max_num;
    }
};

int main()
{
    string t1 = "abcba";
    string t2 = "abcbcba";
    Solution s;
    s.longestCommonSubsequence(t1, t2);
}