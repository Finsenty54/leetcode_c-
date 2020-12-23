#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution
{
private:
    /* data */
public:
   int lengthOfLongestSubstring(string s);
};
int Solution::lengthOfLongestSubstring(string s)
{
    int32_t begin=0,end=0,begin_new=0;
    unordered_map<char,int> windows;
    int count=0;
    
    for (size_t i = 0; i < s.size(); i++)
    {
        //windows.insert(make_pair(s[i],i));
        if(windows.count(s[end])==0)
        {
            windows.insert(make_pair(s[end],end));
            end++;
        }
        else
        {
            //有重复值，那么获得目前的最大值
            if (end-begin>count || count==0)
            {
                count=end-begin;
            }
            begin_new=windows[s[end]]+1;
            //delete 
            for (size_t i = begin; i < begin_new; i++)
            {
                windows.erase(s[i]);
            }
            //插入新的重复值
            windows.insert(make_pair(s[end],end));
            end++;
            begin=begin_new;
        }
    }
    if (end-begin>count)
    {
        count=end-begin;
    }    
    return count;  
}


int main()
{
    string s=" ";
    Solution test;
    cout<<test.lengthOfLongestSubstring(s)<<endl;

}
