#include <bits/stdc++.h>
#include "heightOfTree.cpp"
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

class Diameter : public Height // (https://leetcode.com/problems/diameter-of-binary-tree/)
{
public:
    // The diameter of a binary tree is the length of the longest path between any two nodes in a tree.

    int diameter(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftSubtreeHeight = height(root->left);
        int rightSubtreeHeight = height(root->right);
        int diameterInLeftSubtree = diameter(root->left);
        int diameterInRightSubtree = diameter(root->right);

        int diameterPassingThroughRoot = leftSubtreeHeight + rightSubtreeHeight + 2;

        return max(diameterPassingThroughRoot, max(diameterInLeftSubtree, diameterInRightSubtree));
    }
};