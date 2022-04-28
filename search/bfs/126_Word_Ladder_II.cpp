#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        //将字符串想成节点，用bfs求最短的距离，一维维的逼近
        //而不是一维的遍历每个字符串中的字符，而是直接预处理，其实也用了一点思想
        //同时从两头向中间进行搜索
        vector<vector<string>> ans;
        unordered_set<string> dict;
        for (const auto &w : wordList)
        {
            dict.insert(w);
        }
        if (!dict.count(endWord))
        {
            return ans;
        }
        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_set<string> q1{beginWord}, q2{endWord};
        unordered_map<string, vector<string>> next; //树
        bool reversed = false, found = false;
        while (!q1.empty())
        {
            unordered_set<string> q;
            for (const auto &w : q1) //bfs
            {
                string s = w;
                for (size_t i = 0; i < s.size(); i++) //遍历所有位置的字符，如果相差一个成为子节点
                {
                    char ch = s[i];
                    for (int j = 0; j < 26; j++) //24个字母
                    {
                        s[i] = j + 'a'; 
                        if (q2.count(s))
                        {
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            found = true; //是的话直接找到
                        }
                        if (dict.count(s))
                        {
                            reversed ? next[s].push_back(w) : next[w].push_back(s); //建立树
                            q.insert(s);
                        }
                    }
                    s[i] = ch; //还原
                }
            }
            if (found)
            {
                break;
            }
            for (const auto &w : q)
            {
                dict.erase(w);
            }
            if (q.size() <= q2.size())
            {
                q1 = q;
            }
            else
            {
                reversed = !reversed; //进行反向搜索
                q1 = q2;
                q2 = q;
            }
        }
        if (found)
        {
            vector<string> path = {beginWord};
            backtracking(beginWord, endWord, next, path, ans);
        }
        return ans;
    }
    // 辅函数
    void backtracking(const string &src, const string &dst, unordered_map<string, vector<string>> &next, vector<string> &path, vector<vector<string>> &ans)
    {
        if (src == dst)
        {
            ans.push_back(path);
            return;
        }
        for (const auto &s : next[src]) //回溯，就是dfs，一直沿着路径搜索下去
        {
            path.push_back(s);
            backtracking(s, dst, next, path, ans);
            path.pop_back();
        }
    }
};