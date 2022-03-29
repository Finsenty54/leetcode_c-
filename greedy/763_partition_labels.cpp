#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char,int> first_map;
        unordered_map<char,int> end_map;
        unordered_map<char,int> mycount;
        vector<int> result;
        for (size_t i = 0; i < S.size(); i++)
        {
            if(first_map.count(S[i])==0 && mycount.count(S[i])==0)
            {
                first_map.insert(make_pair(S[i],i));
                mycount.insert(make_pair(S[i],0));
                end_map.insert(make_pair(S[i],i));
            }
            if (mycount.count(S[i]))
            {
                mycount[S[i]]++;
            }
            if (first_map.count(S[i]))
            {
                end_map[S[i]]=i;
            }
        }
        int begin=0,end=0;
        while(true)
        {
            if (mycount[S[begin]]==1)
            {
                result.push_back(1);
            }
            else
            {
                end=end_map[S[begin]];
                int i=begin+1;
                while (true)
                {
                    if(end_map[S[i]]>end)
                    {
                        end=end_map[S[i]];
                    }
                    i++;
                    if (i>end)
                    {
                        break;
                    }
                }
                result.push_back(end-begin+1);                
            }
            begin=end+1;
            end++;
            if (end==S.size())
            {
                break;
            }
        }
        return result;        
    }
};

int main()
{
    Solution test;
    test.partitionLabels("caedbdedda");
}