#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
        {
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b)->bool{
            return a[1]<b[1];//C++11的一大亮点就是引入了Lambda表达式
        });//less<vector<int>>()); 报错
        int total=0,prev=intervals[0][1];//两层怎么取值
        for (size_t i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0]<prev)
                total++;
            else
            {
                prev=intervals[i][1];
            }
            
        }
        return total;

    }
};