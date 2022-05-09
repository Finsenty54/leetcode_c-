#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        /**
         * brief 对于子序列问题，第一种动态规划方法是，定义一个 dp 数组，其中 dp[i] 表示以 i 结尾的子
         * brief 序列的性质。在处理好每个位置后，统计一遍各个位置的结果即可得到题目要求的结果。

         * 
         * date 2022-05-05
         */
        int n = nums.size();
        vector<int> count(n, 1);
        for (int i = 1; i < n; i++)
        {
            int max = 0;
            for (int j = i; j >= 0; j--)
            {
                if (nums[i] > nums[j] && count[j] > max)
                {
                    max = count[j];
                }
            }
            count[i] = max + 1;
        }

        return *max_element(count.begin(), count.end());
    }
};