#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector<int> tmp=prices;
        // unordered_map<int,int> mymap;
        // unordered_map<int,int> place;
        // vector<int> result;
        // sort(tmp.begin(),tmp.end());
        // for (size_t i = 0; i < prices.size(); i++)
        // {
        //     mymap.insert(make_pair(prices[i],i));
        // }
        // for (size_t i = 0; i < tmp.size(); i++)
        // {
        //     place.insert(make_pair(tmp[i],i));
        // }

        int begin=0,end=1,sum=0;
        for (;;) //先弄一个局部最优,
        {
            if (end>=prices.size())
            {
                break;
            }
            
            if(prices[begin]<prices[end])
            {
                sum+=prices[end]-prices[begin]; //全局等于局部加在一起
            }
            begin=end;
            end++;
        }

        return sum;
    }
};

int main()
{
    vector<int> test={7,1,5,3,6,4};
    vector<int> test1={1,2,3,4,5};
    vector<int> test2={7,6,4,3,1};
    Solution t;
    cout<<t.maxProfit(test);
    cout<<t.maxProfit(test1);
    cout<<t.maxProfit(test2);

}