#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp)
{
    if (l + 1 >= r)
    {
        return;
    }
    // divide
    int m = l + (r - l) / 2;
    merge_sort(nums, l, m, temp); //brief 不断递归到最小区间处理，最后进行不断的合并
    merge_sort(nums, m, r, temp);
    // conquer
    int p = l, q = m, i = l;
    while (p < m || q < r)
    {
        if (q >= r || (p < m && nums[p] <= nums[q]))
        {
            temp[i++] = nums[p++];
        }
        else
        {
            temp[i++] = nums[q++];
        }
    }
    for (i = l; i < r; ++i)
    {
        nums[i] = temp[i];
    }
}
