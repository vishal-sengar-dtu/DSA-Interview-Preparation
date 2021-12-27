#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)
{
public:
    void traverse(TreeNode *root, map<int, map<int, multiset<int>>> &mp, int x, int y)
    {
        if (root)
        {
            mp[x][y].insert(root->val);
            traverse(root->left, mp, x - 1, y + 1);
            traverse(root->right, mp, x + 1, y + 1);
        }
        return;
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // mp = < x-coordinate, < y-coordinate, < root->val, . . . > > >
        map<int, map<int, multiset<int>>> mp;
        traverse(root, mp, 0, 0);

        vector<vector<int>> ans;

        for (auto p : mp)
        {
            vector<int> curr_lvl;
            for (auto q : p.second)
            {
                for (int i : q.second)
                {
                    curr_lvl.push_back(i);
                }
            }
            ans.push_back(curr_lvl);
        }
        return ans;
    }
};