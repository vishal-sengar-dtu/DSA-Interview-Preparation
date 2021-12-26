#include <bits/stdc++.h>
#include "heightOfTree.cpp"
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://leetcode.com/problems/symmetric-tree/)
{
    bool areMirror(TreeNode *P, TreeNode *Q)
    {
        // if both P & Q are NULL return true otherwise return false.
        if (P == NULL || Q == NULL)
            return P == Q;

        // if both P & Q are not NULL then return false if their values are different.
        if (P->val != Q->val)
            return false;

        return areMirror(P->left, Q->right) && areMirror(P->right, Q->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return false;
        return areMirror(root->left, root->right);
    }
};