#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // auto begin = nums1.begin(), end = ((nums1.begin() + 1)!=nums1.end())?nums1.begin()+1:nums1.begin();
        // auto b_beg=0,b_end=(nums1.size()==1)?0:1;
        // int n21 = 0;
        // for (;;)
        // {
        //     if (n21>=n)
        //     {
        //         break;
        //     }
        //     auto n2=nums2[n21];
        //     if (n2<*begin)
        //     {
        //         nums1.insert(begin, n2);
        //         ++n21;
        //     }
        //     else if (*begin > *end) //说明到了末尾
        //     {
        //         if (n2 > *begin)
        //         {
        //             nums1.insert(end, n2);
        //         }
        //         else
        //         {
        //             nums1.insert(begin,n2);
        //         }
        //         ++n21;
        //     }
        //     else if (begin==end)
        //     {
        //         nums1.insert(end,n2);
        //         ++n21;
        //     }
        //     else if (n2 >= *begin && n2 <= *end)
        //     {
        //         nums1.insert(end, n2);
        //         ++n21;
        //     }


        //     ++b_beg;
        //     ++b_end;
        //     begin=nums1.begin()+b_beg;
        //     end=nums1.begin()+b_end;
        // }

        // nums1.resize(m + n);

        int pos=m-- + n-- -1;
        while (m>=0&&n>=0)
        {
            nums1[pos--]=nums1[m]>nums2[n] ? nums1[m--]: nums2[n--];
        }
        while (n>=0)
        {
            nums1[pos--]=nums2[n--];
        }
        
    }
};

int main()
{
    int m=3,n=3;
    vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums2={2,5,6};

    Solution s;
    s.merge(nums1,m,nums2,n);

    return 0;
}