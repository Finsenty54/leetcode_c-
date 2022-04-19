#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid;
        if (l==r)
        {
            return nums[0];
        }
        
        while (l<=r)
        {
            mid=(l+r)/2;

            //brief 通过mid不断减少搜索的范围，通过l和r来判断，不会遗漏可能的位置，用mid可能会错过该值
            if (l%2==0 && l+1 < nums.size() && nums[l]!=nums[l+1])
            {
                return nums[l];
            }
            else if (r%2==0 && r-1 >0 && nums[r]!=nums[r-1])
            {
                return nums[l];
            }
            
            if (mid+1<nums.size())
            {
                if (mid%2==0 && nums[mid]==nums[mid+1])
                {
                    l=mid+1;
                }
                else if(mid%2==0 && nums[mid]!=nums[mid+1])
                {
                    r=mid-1;
                }
                else if(mid%2==1 && nums[mid]==nums[mid+1])
                {
                    r=mid-1;
                }
                else if(mid%2==1 && nums[mid]!=nums[mid+1])
                {
                    l=mid+1;
                }
            }
            else
            {
                ++l;
            }
            
        }
        return nums[l];
    }
};

int main()
{
    vector<int> nums={1,1,2};
    Solution s;
    s.singleNonDuplicate(nums);
}