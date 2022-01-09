#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)
{
    bool findPath(TreeNode *root, TreeNode *target, vector<TreeNode *> &path)
    {
        if (root)
        {
            if (root->val == target->val)
            {
                path.push_back(root);
                return true;
            }
            if (findPath(root->left, target, path))
            {
                path.push_back(root);
                return true;
            }
            if (findPath(root->right, target, path))
            {
                path.push_back(root);
                return true;
            }
            return false;
        }
        return false;
    }

    void kLevelsDown(TreeNode *root, int k, vector<int> &ans, TreeNode *blocker)
    {
        if (root == NULL || root == blocker)
            return;

        if (k == 0)
        {
            ans.push_back(root->val);
            return;
        }

        kLevelsDown(root->left, k - 1, ans, blocker);
        kLevelsDown(root->right, k - 1, ans, blocker);
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        vector<TreeNode *> path;

        findPath(root, target, path);
        for (int i = 0; i < path.size() && k >= 0; i++)
        {
            kLevelsDown(path[i], k--, ans, i-1 >= 0 ? path[i-1] : NULL);
        }
        return ans;
    }
};