#include <bits/stdc++.h>
#include "heightOfTree.cpp"
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://leetcode.com/problems/invert-binary-tree/)
{
public:
    TreeNode *invertTree(TreeNode *root) // Recursive Method
    {
        if (root)
        {
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }
        return root;
    }

    TreeNode *invertTree(TreeNode *root) // Iterative Method
    {
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *tmp = st.top();
            st.pop();

            if (tmp)
            {
                st.push(tmp->left);
                st.push(tmp->right);
                swap(tmp->left, tmp->right);
            }
        }
        return root;
    }
};