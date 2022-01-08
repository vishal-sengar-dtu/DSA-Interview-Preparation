#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://www.interviewbit.com/problems/path-to-given-node/)
{
    bool findNode(TreeNode *root, int num, vector<int> &path)
    {
        if (root)
        {
            if (root->val == num)
            {
                path.push_back(root->val);
                return true;
            }
            if (findNode(root->left, num, path))
            {
                path.push_back(root->val);
                return true;
            }
            if (findNode(root->right, num, path))
            {
                path.push_back(root->val);
                return true;
            }
            return false;
        }
        return false;
    }

public:
    vector<int> nodePath(TreeNode *root, int num)
    {
        vector<int> path;
        findNode(root, num, path);
        return path;
    }
};