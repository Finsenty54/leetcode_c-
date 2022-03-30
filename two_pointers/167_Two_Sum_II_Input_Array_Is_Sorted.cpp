#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int begin = 0, end = numbers.size()-1,sum;
        while (begin<end)
        {
            sum=numbers[begin] + numbers[end];
            if (sum==target)
            {
                break;
            }
            else if(sum>target)
            {
                end--;
            }
            else
            {
                begin++;
            }
        }
        return vector<int>{begin + 1, end + 1};
    }
};