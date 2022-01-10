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
            flatten(root->left);

            // Inorder - inserting left subtree between root and right subtree.
            if (root->left)
            {
                TreeNode *tmp = root->right;
                root->right = root->left;
                root->left = NULL;
                
                while (root->right)
                    root = root->right;
                
                root->right = tmp;
            }

            flatten(root->right);
        }
        return;
    }
};