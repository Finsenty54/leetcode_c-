#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    // struct peo
    // {
    //     vector<int> data;
    //     peo* next;
    // };
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        sort(people.begin(),people.end(),[](vector<int> a,vector<int> b)->bool{
            if(a.at(0)<b.at(0))
                return true;
            else
            {
                if (a.at(1)<b.at(1))
                {
                    return true;
                }
                return false;
            }
        });
        auto bin=result.begin();
        for (auto peo:people) //局部最优就是先排最小值
        {
            result.insert(bin+peo.at(1)+1,peo);
        }
        
    }
};