#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Traversal
{
    vector<int> preorder(TreeNode *root, vector<int> &preOrder)
    {
        if (root == NULL)
            return;
        preOrder.push_back(root->val);
        preorder(root->left, preOrder);
        preorder(root->right, preOrder);
    }

    vector<int> inorder(TreeNode *root, vector<int> &inOrder)
    {
        if (root == NULL)
            return;
        inorder(root->left, inOrder);
        inOrder.push_back(root->val);
        inorder(root->right, inOrder);
    }

    vector<int> postorder(TreeNode *root, vector<int> &postOrder)
    {
        if (root == NULL)
            return;
        postorder(root->left, postOrder);
        postorder(root->right, postOrder);
        postOrder.push_back(root->val);
    }

public:
    void dfsTraversal(TreeNode *root)
    {
        vector<int> preOrder, inOrder, postOrder;

        preorder(root, preOrder);
        inorder(root, inOrder);
        postorder(root, postOrder);
    }
};