#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.size()==1)
        {
            return nums[0];
        }
        
        //问题其实是查找边界，确定中间值
        int l = 0, r = nums.size() - 1, mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            // if ((mid+1)!=nums.size() && nums[mid] > nums[mid+1])
            // {
            //     return nums[mid+1];
            // }
            // else if((mid-1)>=0 && nums[mid] < nums[mid-1])
            // {
            //     return nums[mid];
            // }
            
            // if (nums[mid] == nums[l])
            // {
            //     ++l;
            // }
            // else if (nums[mid] <= nums[r])
            if (nums[mid] < nums[r])
            {
                //小于，中间部分在左边
                r=mid;
            }
            else if (nums[mid] > nums[r])
            {

                //大于，中间部分在右边
                l=mid+1;
            }
            else
            {
                //不断减少区间
                --r;
            }
            
        }
        return nums[l];
    }
};

int main()
{
    vector<int> nums={2,2,2,0,1};
    Solution s;
    s.findMin(nums);
    return 0;
}