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
public:

    bool Valid(TreeNode *root, long long mn, long long mx) {
        if (root == NULL)    return true;

        if ( (root->val > mn) && (root->val < mx) && Valid(root->left, mn, root->val) &&
                Valid(root->right, root->val, mx))
            return true;

        return false;
    }

    bool isValidBST(TreeNode* root) {
        return Valid(root, LONG_MIN, LONG_MAX);
    }
};

// https://leetcode.com/problems/validate-binary-search-tree/