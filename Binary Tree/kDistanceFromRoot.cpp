#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://practice.geeksforgeeks.org/problems/k-distance-from-root/1/)
{
    void traverse(TreeNode *root, int k, vector<int> kLevelNodes)
    {
        if (root)
        {
            if (k == 0)
            {
                kLevelNodes.push_back(root->val);
                return;
            }

            traverse(root->left, k - 1, kLevelNodes);
            traverse(root->right, k - 1, kLevelNodes);
        }
        return;
    }

public:
    vector<int> Kdistance(TreeNode *root, int k)
    {
        vector<int> kLevelNodes;
        traverse(root, k, kLevelNodes);
        return kLevelNodes;
    }
};