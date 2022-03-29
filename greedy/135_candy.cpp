#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size=ratings.size();
        if(size<2)
            return size;
        vector<int> num(size,1); //表示有size个元素，初始化值为1
        for (size_t i = 0; i < size-1; ++i) //先加
        {
            if (ratings[i+1]>ratings[i])
            {
                num[i+1]=num[i]+1;
            }
        }
        
        for (size_t i = size-1; i > 0; --i)
        {
            if (ratings[i-1]>ratings[i])
            {
                num[i-1]=max(num[i-1],num[i]+1); //max()
            }
        }
        return accumulate(num.begin(),num.end(),0);
    }
};