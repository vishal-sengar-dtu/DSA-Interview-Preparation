#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://leetcode.com/problems/binary-tree-right-side-view/)
{
public:
    vector<int> rightSideView(TreeNode *root) // Iterative Method
    {
        queue<TreeNode *> Q;
        vector<int> ans;

        if (root == NULL)
            return ans;

        Q.push(root);

        while (!Q.empty())
        {
            int sz = Q.size();

            for (int i = 0; i < sz; i++)
            {
                TreeNode *tmp = Q.front();
                Q.pop();

                if (tmp->left)
                    Q.push(tmp->left);
                if (tmp->right)
                    Q.push(tmp->right);
                if (i == sz - 1)
                {
                    ans.push_back(tmp->val);
                }
            }
        }
        return ans;
    }
};