#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode *> Q;
        Q.push(root);

        while (!Q.empty())
        {
            int sz = Q.size();
            vector<int> curr_Lvl;

            for (int i = 0; i < sz; i++)
            {
                TreeNode *tmp = Q.front();
                Q.pop();
                curr_Lvl.push_back(tmp->val);

                if (tmp->left)
                    Q.push(tmp->left);
                if (tmp->right)
                    Q.push(tmp->right);
            }
            ans.push_back(curr_Lvl);
        }
        return ans;
    }
};