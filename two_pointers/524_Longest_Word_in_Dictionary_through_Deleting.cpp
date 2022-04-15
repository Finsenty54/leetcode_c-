#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        //首先对字典进行排序，按字典最长串
        sort(dictionary.begin(), dictionary.end(), [](string a, string b) -> bool
             {
                 if (a.size() == b.size())
                 {
                     for (int i = 0; i < a.size(); i++)
                     {
                         if (a[i] > b[i])
                         {
                             return false;
                         }
                         else if (a[i] < b[i])
                         {
                             return true;
                         }
                     }
                     return false;
                 }
                 else if (a.size() > b.size())
                 {
                     return true;
                 }
                 else
                 {
                     return false;
                 } });
        int begin=0,end=0;
        for (auto iter : dictionary)
        {
            for (; begin < s.size() && end<iter.size(); begin++)
            {
                if (s[begin]==iter[end])
                {
                    end++;
                }
            }
            if (end==iter.size())
            {
                return iter;
            }
            begin=0;
            end=0;
        }
        return "";
    }
};