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
    void countGoodNodes(TreeNode *root, int &count, int maxSoFar) {
        if (root == NULL)    return;
        if (root->val >= maxSoFar) {
            maxSoFar = root->val;
            count++;
        }
        countGoodNodes(root->left, count, maxSoFar);
        countGoodNodes(root->right, count, maxSoFar);
    }

public:
    int goodNodes(TreeNode* root) {
        if (root == NULL)    return 0;
        int count = 0;
        countGoodNodes(root, count, root->val);
        return count;
    }
};

// https://leetcode.com/problems/count-good-nodes-in-binary-tree/