#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1)
{
    bool isLeaf(TreeNode *root)
    {
        return (!root->left && !root->right) ? true : false;
    }

    void addLeftBoundary(TreeNode *root, vector<int> &ans)
    {
        TreeNode *tmp = root->left;

        while (tmp)
        {
            if (!isLeaf(tmp))
                ans.push_back(tmp->val);

            tmp = tmp->left ? tmp->left : tmp->right;
        }
    }

    void addLeafNodes(TreeNode *root, vector<int> &ans)
    {
        if (isLeaf(root))
            ans.push_back(root->val);

        if (root->left)
            addLeafNodes(root->left, ans);
        if (root->right)
            addLeafNodes(root->right, ans);
    }

    void addRightBoundary(TreeNode *root, vector<int> &ans)
    {
        vector<int> right;
        TreeNode *tmp = root->right;

        while (tmp)
        {
            if (!isLeaf(tmp))
                right.push_back(tmp->val);

            tmp = tmp->right ? tmp->right : tmp->left;
        }

        reverse(right.begin(), right.end());

        for (int i : right)
            ans.push_back(i);
    }

public:
    vector<int> boundary(TreeNode *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        if (!isLeaf(root))
            ans.push_back(root->val);

        addLeftBoundary(root, ans);
        addLeafNodes(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};