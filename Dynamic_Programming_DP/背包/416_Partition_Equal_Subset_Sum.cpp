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
    bool canPartition(vector<int> &nums)
    {
        //总和取一半
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
        {
            return false;
        }
        int target = sum / 2, n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                if (j >= nums[i-1])
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i-1]]; //brief 0，1背包问题,总是放入刚好体积大小相等的位置
                                                                         //brief 即 位置j (放入的加在一起等于j)
                                                                         //brief 放入了可以放入的地方，之后不会再放，全为false
                                                                         //brief 这里转移函数做了变化，不是传统的
                }
                else                                                     //brief 分发糖果也可以用0，1背包套用
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target];
    }
};

int main()
{
    vector<int> nums={1,5,11,5};
    Solution s;
    s.canPartition(nums);
}