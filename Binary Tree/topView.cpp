#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1)
{
    void traverse(TreeNode *root, map<int, vector<int>> &mp, int x)
    {
        if (root)
        {
            mp[x].push_back(root->val);
            traverse(root->left, mp, x - 1);
            traverse(root->right, mp, x + 1);
        }
        return;
    }

public:
    vector<int> topView(TreeNode *root) // Recursive Method
    {
        // mp = < x-coordinate, < root->val, . . . >  >
        map<int, vector<int>> mp;
        traverse(root, mp, 0);

        vector<int> ans;

        for (auto p : mp)
        {
            ans.push_back(p.second[0]);
        }
        return ans;
    }

    vector<int> topView(TreeNode *root) // Iterative Method
    {
        queue<pair<TreeNode *, int>> Q;
        map<int, vector<int>> mp;

        Q.push({root, 0});

        while (!Q.empty())
        {
            pair<TreeNode *, int> tmp = Q.front();
            TreeNode *node = tmp.first;
            int x = tmp.second;

            Q.pop();
            mp[x].push_back(node->val);

            if (node->left)
                Q.push({node->left, x - 1});
            if (node->right)
                Q.push({node->right, x + 1});
        }

        vector<int> ans;

        for (auto &p : mp)
            ans.push_back(p.second[0]);

        return ans;
    }
};