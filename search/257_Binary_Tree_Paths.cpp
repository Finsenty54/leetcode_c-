#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// /**
//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//  */
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        string an;
        an.append(to_string(root->val));
        backtracking(root, ans, an);
        return ans;
    }

    void backtracking(TreeNode *root, vector<string> &ans, string &an)
    {
        if (root->left != nullptr)
        {
            string tmp = "->" + to_string(root->left->val);
            an.append(tmp);
            backtracking(root->left, ans, an);
            an.erase(an.size() - tmp.size(), tmp.size());
        }
        if (root->right != nullptr)
        {
            string tmp = "->" + to_string(root->right->val);
            an.append(tmp);
            backtracking(root->right, ans, an);
            an.erase(an.size() - tmp.size(), tmp.size());
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(an);
        }
    }
};