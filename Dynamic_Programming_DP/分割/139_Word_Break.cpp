#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.length(); //每个位置都进行比较
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            for (const string &word : wordDict) //遍历所有可能值
            {
                int len = word.length();
                if (i >= len && s.substr(i - len, len) == word)
                {
                    dp[i] = dp[i] || dp[i - len]; // || 逻辑或运算符， 之前位置可以分割，那么当前位置也可以分割
                                                  // 加上dp[i] 是可能已经可以分割，再来一个却不能分割，防止答案替换掉
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    vector<string> words={"cats","dog","sand","and","cat"};
    Solution s;
    s.wordBreak("catsandog",words);
}