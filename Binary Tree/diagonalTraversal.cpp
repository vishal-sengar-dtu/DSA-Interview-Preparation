#include <bits/stdc++.h>
#include "heightOfTree.cpp"
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1)
{
    void traverse(TreeNode *root, int dd, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;

        if (ans.size() == dd)
            ans.push_back(vector<int>());

        ans[dd].push_back(root->val);

        traverse(root->left, dd + 1, ans);
        traverse(root->right, dd, ans);
    }

public:
    // Diagonal with slope -1;

    vector<vector<int>> diagonalTraversal(TreeNode *root) // Recursive Method (order - branch wise)
    {
        vector<vector<int>> ans;
        traverse(root, 0, ans);
        return ans;
    }

    vector<int> diagonal(TreeNode *root) // Iterative Method (order - level wise)
    {
        queue<pair<int, TreeNode *>> Q;
        map<int, vector<int>> mp;
        vector<int> ans;

        if (root == NULL)
            return ans;

        Q.push({0, root});

        while (!Q.empty())
        {
            pair<int, TreeNode *> pr = Q.front();
            int dd = pr.first;
            TreeNode *node = pr.second;
            Q.pop();

            mp[dd].push_back(node->val);

            if (node->left)
                Q.push({dd + 1, node->left});
            if (node->right)
                Q.push({dd, node->right});
        }

        for (auto &it : mp)
            for (int n : it.second)
                ans.push_back(n);

        return ans;
    }
};