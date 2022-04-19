#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // quicksort(nums, 0, nums.size());
        // vector<int> target;
        // target.push_back(nums[0]);
        // for (size_t i = 1, j = 1; i < k && j < nums.size(); j++)
        // {
        //     if (nums[j] != nums[j - 1])
        //     {
        //         target.push_back(nums[j]);
        //         i++;
        //     }
        // }
        // return target;

        // brief 桶排序
        // 桶排序的意思是为每个值设立一个桶，桶内记录这个值出现的次数（或其它属
        // 性），然后对桶进行排序。
        unordered_map<int, int> counts;
        int max_count = 0;
        for (const int &num : nums)
        {
            max_count = max(max_count, ++counts[num]);
        }
        vector<vector<int>> buckets(max_count + 1);
        for (const auto &p : counts)
        {
            buckets[p.second].push_back(p.first);
        }
        vector<int> ans;
        for (int i = max_count; i >= 0 && ans.size() < k; --i)
        {
            for (const int &num : buckets[i])
            {
                ans.push_back(num);
                if (ans.size() == k)
                {
                    break;
                }
            }
        }
        return ans;
    }

    void quicksort(vector<int> &nums, int l, int r)
    {
        if (l + 1 >= r)
            return;
        int low = l, high = r - 1, tar = nums[l];
        while (low < high)
        {
            while (low < high && nums[high] >= tar)
            {
                --high;
            }
            nums[low] = nums[high]; // brief 换了也不要紧，high是小的，是对的；将tar做为中间值
            while (low < high && nums[low] <= tar)
            {
                ++low;
            }
            nums[high] = nums[low]; // brief 上面high不变，将low替换为high，再一次循环，low值已保存可以替换
        }
        nums[low] = tar;
        quicksort(nums, l, low);
        quicksort(nums, low + 1, r);
    }
};

int main()
{
    vector<int> nums = {4, 1, -1, 2, -1, 2, 3};
    Solution s;
    s.topKFrequent(nums, 2);
}