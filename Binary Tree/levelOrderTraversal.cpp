#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://leetcode.com/problems/binary-tree-level-order-traversal/)
{
    vector<vector<int>> lvlOrder;

    void helper(TreeNode *root, int level)
    {
        if (root == NULL)
            return;

        if (lvlOrder.size() == level)
            lvlOrder.push_back(vector<int>());

        lvlOrder[level].push_back(root->val);

        helper(root->left, level + 1);
        helper(root->right, level + 1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root) // Iterative Method
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

    vector<vector<int>> levelOrder(TreeNode *root) // Recursive Method
    {
        helper(root, 0);
        return lvlOrder;
    }
};