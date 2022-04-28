#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        //重复元素相等就不换

        vector<vector<int>> ans;
        // ans.push_back(nums);
        dfs(ans, 0, nums);
        sort(ans.begin(), ans.end());
        auto end = unique(ans.begin(), ans.end());
        ans.erase(end, ans.end());
        return ans;

///////////////////////////////////////////////////////
        const int n = nums.size();
        vector<vector<int>> ans;
        unordered_map<int, int> used; //记录出现的次数
        for (auto num : nums)
            used[num]++;
        vector<int> path;
        function<void(int)> dfs = [&](int d)
        {
            if (d == n)
            {
                ans.push_back(path);
                return;
            }
            for (auto [key, value] : used)
            {
                if (value == 0)
                    continue;
                used[key]--;
                path.push_back(key);
                dfs(d + 1);
                path.pop_back();
                used[key]++;
            }
        };
        dfs(0);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, int level, vector<int> &nums)
    {
        if (level == nums.size() - 1) //当到达最底层才推入
        {
            ans.push_back(nums);
            return;
        }
        for (int i = level; i < nums.size(); i++)
        {
            // if (i == 0)
            // {
            //     ans.push_back(nums);
            //     dfs(ans, level + 1, nums);
            // }
            // else
            // {
            if (i != level && nums[i] == nums[level])
            {
                continue;
            }
            swap(nums[i], nums[level]);
            dfs(ans, level + 1, nums);
            swap(nums[i], nums[level]);
            // }
        }
    }
};