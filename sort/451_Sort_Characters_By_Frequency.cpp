#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> fre;
        int max_count=0;
        for (const auto &it:s)
        {
            max_count=max(max_count,++fre[it]);
        }
        vector<vector<char>> bucket(max_count+1);
        for (const auto &it:fre)
        {
            bucket[it.second].push_back(it.first);
        }
        string tar;
        for (int i = max_count; i >=0; i--)
        {
            for (const auto &it:bucket[i]) //brief 为空，不会进入循环
            {
                for (int j=0;j<i;j++)
                {
                    tar.push_back(it);
                }
            }
        }
        return tar;
    }
};

int main()
{
    string s="Aabb";
    Solution w;
    w.frequencySort(s);
}