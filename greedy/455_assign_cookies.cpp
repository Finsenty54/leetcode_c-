#include<iostream>
#include<algorithm>
//使用sort()，排序
#include<vector>
#include<functional>
/*functional提供了一堆基于模板的比较函数对象，
它们是：equal_to<Type>、not_equal_to<Type>、greater<Type>、
greater_equal<Type>、less<Type>、less_equal<Type>。*/

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),less<int>());//小于-升序，greater<>()降序
        sort(s.begin(),s.end());
        int child=0,cookie=0;
        while (child<g.size() && cookie<s.size())
        {
            if(g[child]<=s[cookie]) child++; //vector 取值是这样的， 和数组取值相同
            cookie++;
        }
        return child;
    }
};