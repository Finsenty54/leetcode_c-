#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        int begin = 0, end = s.size() - 1;
        int cnt = 0, rem_b = 0, rem_e = 0, tar = 0;
        bool flag = false;
        while (begin < end)
        {
            if (s[begin] != s[end])
            {
                tar = end;
                if (cnt == 1 && !flag) //回退，重新尝试删另一边
                {
                    begin = rem_b;
                    end = rem_e;
                    tar = begin;
                    cnt--;
                    flag = true;
                }
                else if (cnt == 1 && flag)
                {
                    return false;
                }

                // s.erase(tar);
                rem_b = begin;
                rem_e = end;
                cnt++;
                if (!flag)
                {
                    end--;
                }
                else
                {
                    begin++;
                }
                
            }
            else
            {
                end--;
                begin++;
            }
        }
        return true;
    }
};