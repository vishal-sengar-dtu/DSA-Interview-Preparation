#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Solution // (https://leetcode.com/problems/binary-tree-maximum-path-sum/)
{
    int ans;

public:
    int helper(TreeNode *root)
    {
        if (root)
        {
            // max path sum with split, take it as 0 if returned value is (-ve).
            int l = max(0, helper(root->left));
            int r = max(0, helper(root->right));

            // updating the max path sum with split in the subtree.
            int pathSum = l + root->val + r;
            ans = max(ans, pathSum);

            // passing the max path sum without split from the subtree.
            return root->val + max(l, r);
        }
        return 0;
    }

    int maxPathSum(TreeNode *root) // Time O(N), Space O(log(N))
    {
        ans = INT_MIN;
        helper(root);
        return ans;
    }
};