#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // 状态转移方程
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]); //我想到了取 i-1 或者 i-2, 但没有想到取最大值
        }
        return dp[n];
    }
};