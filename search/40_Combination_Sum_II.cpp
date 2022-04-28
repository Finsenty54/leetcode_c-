#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // brief 原来想用乘法去重，有可能会溢出
        unordered_map<int, vector<int>> have;
        // vector<vector<int>> ans;
        vector<int> an;
        int count = 0, mul = 1;
        sort(candidates.begin(), candidates.end());
        for (int num : candidates)
        {
            if (freq.empty() || num != freq.back().first)
            {
                freq.emplace_back(num, 1);
            }
            else
            {
                ++freq.back().second;
            }
        }
        dfs(0, target);

        // dfs(have, ans, an, candidates, 0, count, mul, target);
        return ans;
    }
    void dfs(int pos, int rest)
    {
        if (rest == 0)
        {
            ans.push_back(sequence);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first)
        {
            return;
        }

        dfs(pos + 1, rest);

        int most = min(rest / freq[pos].first, freq[pos].second); //重复元素最多可以取几次
        for (int i = 1; i <= most; ++i)
        {
            sequence.push_back(freq[pos].first); //其实第一次想法是这个
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; ++i)
        {
            sequence.pop_back();
        }

        // if (count == target)
        // {
        //     if (have.count(mul) == 0)
        //     {
        //         ans.push_back(an);
        //         have.insert({mul, vector<int>(1, an.size())});
        //     }
        //     else
        //     {
        //         if (find(have[mul].begin(), have[mul].end(), an.size()) == have[mul].end())
        //         {
        //             ans.push_back(an);
        //             have[mul].push_back(an.size());
        //         }
        //     }
        // }

        // for (int i = level; i < candidates.size(); i++)
        // {
        //     an.push_back(candidates[i]);
        //     count += candidates[i];
        //     mul *= candidates[i];
        //     dfs(have, ans, an, candidates, i + 1, count, mul, target);
        //     an.pop_back();
        //     count -= candidates[i];
        //     mul /= candidates[i];
        // }
    };
};

int main()
{
    vector<int> candidates = {2, 5, 2, 1, 1, 2, 1, 2};
    Solution S;
    S.combinationSum2(candidates, 5);
}