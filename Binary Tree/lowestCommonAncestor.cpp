#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
{
    bool findNode(TreeNode *root, TreeNode *node, vector<TreeNode *> &path)
    {
        if (root)
        {
            if (root->val == node->val)
            {
                path.push_back(root);
                return true;
            }
            if (findNode(root->left, node, path))
            {
                path.push_back(root);
                return true;
            }
            if (findNode(root->right, node, path))
            {
                path.push_back(root);
                return true;
            }
            return false;
        }
        return false;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) // naive approch
    {
        vector<TreeNode *> pathP, pathQ;
        TreeNode *LCA = NULL;

        findNode(root, p, pathP);
        findNode(root, q, pathQ);

        int i = pathP.size() - 1;
        int j = pathQ.size() - 1;

        while (pathP[i] == pathQ[j--])
            LCA = pathP[i--];

        return LCA;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) // optimized approch using recursion
    {
        if (root == p || root == q || root == NULL)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if(left && right)
            return root;
            
        return left ? left : right;
    }
};