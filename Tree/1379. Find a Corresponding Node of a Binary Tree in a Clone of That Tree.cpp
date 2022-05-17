/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* search(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == NULL)    return NULL;
        if (original == target)  return cloned;
        TreeNode *left = search(original->left, cloned->left, target);
        if (left)    return left;
        TreeNode *right = search(original->right, cloned->right, target);
        if (right)   return right;
        return NULL;
    }

public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return search(original, cloned, target);
    }
};

// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/submissions/