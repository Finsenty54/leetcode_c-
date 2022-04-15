#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

void insertion_sort(vector<int> &nums, int n)
{
    for (int i = 0; i < n; ++i) //brief 不断迭代进行
    {
        for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j)
        {
            swap(nums[j], nums[j - 1]);
        }
    }
}