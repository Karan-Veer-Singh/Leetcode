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
    bool isLeaf(TreeNode *root) {
        return (root->left == NULL && root->right == NULL);
    }

    void getPath(TreeNode *root, vector<string> &path, string s) {
        if (root == NULL)    return;
        s += to_string(root->val);
        if (isLeaf(root)) { path.push_back(s); return;}
        s += "->";
        getPath(root->left, path, s);
        getPath(root->right, path, s);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        getPath(root, path, "");
        return path;
    }
};

// https://leetcode.com/problems/binary-tree-paths/