#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> q = {0};
        q.resize(n+1);
        if (n<=2)
        {
            return n;
        }
        q[0]=0;
        q[1]=1;
        q[2]=2;

        for (int i = 3; i < n+1; i++)
        {
            q[i]=q[i-1]+q[i-2]; //brief 我们每次可以走一步或者两步，所以第 i 阶可以从第 i-1 或 i-2 阶到达
        }
        return q[n];
        
    }
};