#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Height // (https://leetcode.com/problems/maximum-depth-of-binary-tree/)
{
public:
    // height = -1 ; for empty tree.

    int height(TreeNode *root)
    {
        if (root == NULL)
            return -1;

        return 1 + max(height(root->left), height(root->right));
    }
};