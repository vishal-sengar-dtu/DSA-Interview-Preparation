#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://leetcode.com/problems/binary-tree-paths/)
{
    bool isLeaf(TreeNode *node)
    {
        if(!node->left && !node->right)
            return true;
        return false;
    }

    void traverse(TreeNode *root, string path, vector<string> &rootToLeafPaths)
    {
        if (root)
        {
            path += to_string(root->val);
            if(isLeaf(root))
                rootToLeafPaths.push_back(path);
            else
                path += "->";

            traverse(root->left, path, rootToLeafPaths);
            traverse(root->right, path, rootToLeafPaths);
        }
        return;
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> rootToLeafPaths;
        string path = "";
        traverse(root, path, rootToLeafPaths);
        return rootToLeafPaths;
    }
};