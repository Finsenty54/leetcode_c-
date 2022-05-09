#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {

        //分成两类，一类是以两个值结尾的，另一类是以一个值结尾的
        vector<int> dp2(s.size() + 1, 0);
        vector<int> dp1(s.size() + 1, 0);

        if (s[0] == '0')
        {
            return 0;
        }
        if (s.size() == 1)
        {
            return 1;
        }

        dp1[1] = 1;
        for (int i = 2; i <= s.size(); i++)
        {
            if (s[i - 2] == '1' || (s[i-2]=='2' && s[i - 1] < '7'))
            {
                dp2[i] = dp1[i - 1];
            }
            if (s[i - 1] != '0')
            {
                dp1[i] = dp2[i - 1] + dp1[i - 1];
            }
        }

        return dp2[s.size()] + dp1[s.size()];
    }
};

int main()
{
    string s = "2611055971756562";
    Solution S;
    int re= S.numDecodings(s);
}