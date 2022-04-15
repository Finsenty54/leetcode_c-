#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

void selection_sort(vector<int> &nums, int n)
{
    int mid;
    for (int i = 0; i < n - 1; ++i)
    {
        mid = i;
        for (int j = i + 1; j < n; ++j) //brief 每次得到最小值
        {
            if (nums[j] < nums[mid])
            {
                mid = j;
            }
        }
        swap(nums[mid], nums[i]);
    }
}