#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        /**
         * brief 快速选择一般用于求解 k-th Element 问题，可以在 O(n) 时间复杂度，O(1) 空间复杂度完成求
                 解工作。
         *
         * date 2022-04-18
         */
        // for (size_t i = 0; i < k; i++)
        // {
        //     for (size_t j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[i] < nums[j])
        //         {
        //             swap(nums[i], nums[j]);
        //         }
        //     }
        // }

        // return nums[k - 1];

        int l = 0, r = nums.size() - 1, target = nums.size() - k; //brief 升序，所以得到相反顺序的值
        while (l < r)
        {
            int mid = quickSelection(nums, l, r);
            if (mid == target)
            {
                return nums[mid];
            }
            if (mid < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return nums[l];
    }

    // 辅函数 - 快速选择
    int quickSelection(vector<int> &nums, int l, int r) //brief 返回第几大的位置
    {
        int i = l + 1, j = r;
        while (true)
        {
            while (i < r && nums[i] <= nums[l])
            {
                ++i;
            }
            while (l < j && nums[j] >= nums[l])
            {
                --j;
            }
            if (i >= j) //brief 到达小大交错点，已经成功的分在了两边
            {
                break;
            }
            swap(nums[i], nums[j]); //brief 跳到这里，nums[i] 大于 nums[l], nums[j] 小于 nums[l], 进行交换
        }
        swap(nums[l], nums[j]); //brief 小于和大于基准的元素分在基准左边和右边的两个区域
        return j;
    }
};

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    Solution s;
    s.findKthLargest(nums, 2);
}