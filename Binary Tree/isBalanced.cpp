#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://leetcode.com/problems/balanced-binary-tree/)
{
public:
    int height(TreeNode *root)
    {
        if (root)
        {
            return 1 + max(height(root->left), height(root->right));
        }
        return 0;
    }

    bool isBalanced(TreeNode *root)
    {
        if (root)
        {
            int l = height(root->left);
            int r = height(root->right);

            return abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
        return true;
    }
};