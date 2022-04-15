#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

void bubble_sort(vector<int> &nums, int n)
{
    bool swapped;
    for (int i = 1; i < n; ++i)
    {
        swapped = false;
        for (int j = 1; j < n - i + 1; ++j) //https://www.runoob.com/w3cnote/bubble-sort.html 最大的会移动到最后
        {
            if (nums[j] < nums[j - 1])
            {
                swap(nums[j], nums[j - 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}