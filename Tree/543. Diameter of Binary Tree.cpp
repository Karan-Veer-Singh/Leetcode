/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int height(TreeNode *root, int &diameter) {
        if (root == NULL)    return 0;
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};

-------------------------------------------------------------------------- -
class Solution {
public:

    class Pair
    {
    public:
        int height;
        int diameter;
    };

    Pair diameter(TreeNode *root)
    {
        Pair p;

        if (root == NULL)
        {
            p.height = p.diameter = 0;
            return p;
        }

        Pair left = diameter(root -> left);
        Pair right = diameter(root -> right);

        p.height = 1 + max(left.height, right.height);
        p.diameter = max({(left.height + right.height), left.diameter, right.diameter});

        return p;
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        Pair p = diameter(root);
        return p.diameter;
    }
};

// https://leetcode.com/problems/diameter-of-binary-tree/submissions/
