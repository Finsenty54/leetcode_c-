#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;

        //brief 有三种情况，先进行好处理得两种
        //brief 判断哪一部分是排好序的
        while (l<=r)
        {
            mid=(l+r)/2;
            if (nums[mid]==target)
            {
                return true;
            }
            
            if (nums[mid]==nums[l])
            {
                ++l;
            }
            else if (nums[mid]<=nums[r])
            {
                if (nums[mid]<target && target <=nums[r])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
                
            }
            else
            {
                if (nums[mid]>target && target >=nums[l])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
        }
        return false;
    }
};