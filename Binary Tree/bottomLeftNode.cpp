#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://leetcode.com/problems/find-bottom-left-tree-value/)
{
    void dfs(TreeNode *root, int &value, int &maxDepth, int currLvl)
    {
        if (root)
        {
            if (currLvl > maxDepth)
            {
                value = root->val;
                maxDepth = currLvl;
            }

            dfs(root->left, value, maxDepth, currLvl + 1);
            dfs(root->right, value, maxDepth, currLvl + 1);
        }
        return;
    }

public:
    int findBottomLeftValue(TreeNode *root) // Space Optimized Solution
    {
        int value, maxDepth = -1;
        dfs(root, value, maxDepth, 0);
        return value;
    }
};