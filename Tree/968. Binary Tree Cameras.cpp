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

// -1 -> Need a camera.
// 0  -> has a camera.
// 1  -> covered by a camera.

class Solution {
private:
    int minCamera(TreeNode *root, int &cameras) {
        if (root == NULL)    return 1;

        int leftChild = minCamera(root->left, cameras);
        int rightChild = minCamera(root->right, cameras);

        if (leftChild == -1 || rightChild == -1) { cameras++; return 0;}
        if (leftChild == 0 || rightChild == 0)   return 1;
        return -1;
    }

public:
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        if (minCamera(root, cameras) == -1)  cameras++;
        return cameras;
    }
};

// https://leetcode.com/problems/binary-tree-cameras/