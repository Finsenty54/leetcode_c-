#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int count = 0;
        if (nums.size()==1)
        {
            return true;
        }
        
        if (nums[0] > nums[1])
        {
            count++;
        }

        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                if (nums[i + 1] >= nums[i - 1])
                {
                    count++;
                }
                else
                {
                    nums[i + 1] = nums[i]; //修改值，最少也是与前一个值相同
                    count++;
                }
            }

            if (count == 2)
                return false;
        }
        return true;
    }
};