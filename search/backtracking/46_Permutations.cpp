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
    int n = 0;
    vector<vector<int>> permute(vector<int> &nums) //先有一个思路，不要强代具体方法，比如回溯
    {
        n = nums.size();
        vector<vector<int>> results;

        recusion(nums, results, 0);

        return results;
    }

    void recusion(vector<int> &nums, vector<vector<int>> &results, int level)
    {
        if (level == n - 1)
        {
            results.push_back(nums);
            return;
        }

        for (int i = level; i < n; i++) //brief 递归每个位置交换
        {
            swap(nums[i], nums[level]);
            recusion(nums, results, level + 1);
            swap(nums[i], nums[level]);
        }
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution s;
    s.permute(nums);
}