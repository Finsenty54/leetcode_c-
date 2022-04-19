#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

void quick_sort(vector<int> &nums, int l, int r)
{
    if (l + 1 >= r)
    {
        return;
    }
    int first = l, last = r - 1, key = nums[first]; //brief =r-1就是右开 =l就是左闭
    while (first < last)
    {
        while (first < last && nums[last] >= key)
        {
            --last;
        }
        nums[first] = nums[last];
        while (first < last && nums[first] <= key)
        {
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
}
