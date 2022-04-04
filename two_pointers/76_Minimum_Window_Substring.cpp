#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<bool> flag(128, false);
        vector<int> chars(128, 0);

        for (int i = 0; i < t.size(); i++)
        {
            flag[t[i]] = true;
            ++chars[t[i]];
        }

        int length = 0, l = 0, l_size = s.size() + 1, min_l = 0;
        for (int r = 0; r < s.size(); r++) //右指针一直加
        {
            if (flag[s[r]])
            {
                if (--chars[s[r]] >=0) //还缺少的字符数量减-1, 如果已经有了, 不用再包含,length不用加
                    ++length;

                while (length == t.size()) //当有一个解，尝试将 左指针加1，找到最小窗口
                {
                    if (r - l + 1 < l_size)
                    {
                        min_l = l; //先保留，后面找不到就是这个解
                        l_size = r - l + 1;
                    }

                    if (flag[s[l]] && ++chars[s[l]] > 0) //回退回去
                    {
                        --length;
                    }
                    ++l;
                }
            }
        }

        return l_size>s.size()? "":s.substr(min_l,l_size);
    }
};