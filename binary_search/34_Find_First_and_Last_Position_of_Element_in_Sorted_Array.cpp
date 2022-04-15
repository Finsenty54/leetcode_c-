#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
        {
            return vector<int>{-1, -1};
        }

        // int tar_l=-1,tar_h=-1;
        // int begin=0,end=nums.size(),middle;
        // while (begin<end)
        // {
        //     middle=begin+(end-1)/2;
        //     if (nums[middle]<target)
        //     {
        //         begin=middle+1;
        //     }
        //     else if(nums[middle]>=target)
        //     {
        //         end=middle; //brief 左闭右开
        //     }
        // }
        // tar_l=end;
        // begin=0;
        // end=nums.size();
        // while (begin<end)
        // {
        //     middle=begin+(end-1)/2;
        //     if (nums[middle]<=target)
        //     {
        //         begin=middle+1;
        //     }
        //     else if(nums[middle]>target)
        //     {
        //         end=middle;
        //     }
        // }
        // tar_h=end-1;
        int tar_l=lower_bound(nums,target);
        int tar_h=upper_bound(nums,target)-1;
        if (tar_l == nums.size() - 1 || nums[tar_l] != target)
        {
            return vector<int>{-1, -1};
        }
        return vector<int>{tar_l, tar_h};
    }

    int lower_bound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size(), mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] >= target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
    // 辅函数
    int upper_bound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size(), mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] > target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};


int main()
{
    vector<int> nums={5,7,7,8,8,10};

    Solution S;
    S.searchRange(nums,8);
    return 0;
}