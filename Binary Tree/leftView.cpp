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
    void traverse(TreeNode *root, int lvl, vector<int> &ans)
    {
        if (root == NULL)
            return;

        if (ans.size() == lvl)
            ans.push_back(root->val);

        traverse(root->left, lvl + 1, ans);
        traverse(root->right, lvl + 1, ans);
    }

public:
    vector<int> leftView(TreeNode *root) // Recursive Method
    {
        vector<int> ans;
        traverse(root, 0, ans);
        return ans;
    }

    vector<int> leftSideView(TreeNode *root) // Iterative Method
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
                if (i == 0)
                {
                    ans.push_back(tmp->val);
                }
            }
        }
        return ans;
    }
};