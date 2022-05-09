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
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        if (k <= 0 || sum % k != 0)
        {
            return false;
        }
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end(), greater<int>()); //brief 排序会快很多
        return canPartition(nums, visited, 0, k, 0, sum / k);
    }

    /**
     * brief 本来想得也是回溯，按集合来，满足一个集合再下一个集合
     *
     * date 2022-05-09
     */
    bool canPartition(vector<int> nums, vector<bool> visited, int start_index, int k, int cur_sum, int target)
    {
        if (k == 1) // brief 剩下的一份肯定是满足的，等于1直接返回
        {
            return true;
        }
        // if (cur_sum > target)
        // {
        //     return false;
        // }
        if (cur_sum == target)
        {
            return canPartition(nums, visited, 0, k - 1, 0, target); // brief 再接着下去，之前用到的不会因为回溯改为false
        }                                                            // brief 这就解决了 回溯会重新更新值的问题
        for (int i = start_index; i < nums.size(); i++)
        {
            if (i > 0 && !visited[i - 1] && nums[i] == nums[i - 1])
                continue;
            if (visited[i] == false && cur_sum + nums[i] <= target)
            {
                visited[i] = true;                                                    // brief 回溯，如果不行重新回来
                if (canPartition(nums, visited, i + 1, k, cur_sum + nums[i], target)) // brief 再下一个
                {
                    return true; // brief 成功，中断递归直接返回true
                }
                visited[i] = false;
            }
        }
        return false;
    }

    //brief 按每个数字解决，遍历所有数字应该放在那个集合中
    bool solve(vector<int> &nums, int &target, int idx, vector<int> &map)
    {
        if (idx == nums.size())
        {
            for (int i = 0; i < map.size(); i++)
            {
                if (map[i] != target)
                    return false;
            }
            return true;
        }
        for (int i = 0; i < map.size(); i++)
        {
            if (map[i] + nums[idx] <= target)
            {
                map[i] += nums[idx];
                if (solve(nums, target, idx + 1, map)) //brief 对直接返回true
                    return true;
                map[i] -= nums[idx];
                if (map[i] == 0)
                    break;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0;
        for (int &num : nums)
            sum += num;
        if (sum % k)
            return false;
        sum /= k;
        vector<int> map(k, 0);
        sort(nums.begin(), nums.end(), greater<int>()); //brief 排序
        return solve(nums, sum, 0, map);
    }
};