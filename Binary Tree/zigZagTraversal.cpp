#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        bool level = 0;
        queue<TreeNode *> Q;
        Q.push(root);

        while (!Q.empty())
        {
            int sz = Q.size();
            vector<int> curr_lvl(sz);

            for (int i = 0; i < sz; i++)
            {
                TreeNode *tmp = Q.front();
                Q.pop();

                if (level == 0)
                    curr_lvl[i] = tmp->val;
                else
                    curr_lvl[sz - i - 1] = tmp->val;

                if (tmp->left)
                    Q.push(tmp->left);
                if (tmp->right)
                    Q.push(tmp->right);
            }
            
            ans.push_back(curr_lvl);
            level = !level; // // toggle the level using negation.
        }
        return ans;
    }
};