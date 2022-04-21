#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> results;

        // if (n == 1)
        // {
        //     results.push_back({1});
        //     return results;
        // }
        vector<int> res;

        for (int i = 1; i <= n; i++)
        {
            res.push_back(i);
            recusion(results, res, i, n, k);
            res.pop_back();
        }
        return results;
    }

    void recusion(vector<vector<int>> &results, vector<int> &res, int level, int &n, int &k)
    {
        if (res.size() == k)
        {
            results.push_back(res);
            return;
        }

        if (level == n)
        {
            return;
        }

        for (int i = level + 1; i <= n; i++)
        {
            res.push_back(i);
            recusion(results, res, i, n, k);
            res.pop_back();
        }
    }
};

int main()
{
    Solution s;
    s.combine(1, 1);
}