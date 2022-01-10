#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)
{
public:
    void flatten(TreeNode *root)
    {
        if (root)
        {
            // Move the left subtree between root and the right subtree.
            TreeNode *tmp = root->right;
            root->right = root->left;
            root->left = NULL;

            TreeNode *node = root;
            while (node->right)
                node = node->right;

            // Append the right subtree here
            node->right = tmp;

            flatten(root->right);
        }
        return;
    }
};