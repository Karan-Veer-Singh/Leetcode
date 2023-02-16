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
    int maxDepth(TreeNode* root) {
        if (root == NULL)    return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};

-------------------------------------------------------------------------- -

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)    return 0;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                TreeNode *front = q.front();
                q.pop();

                if (front->left != NULL) q.push(front->left);
                if (front->right != NULL)    q.push(front->right);
            }

            level++;
        }

        return level;
    }
};

// https://leetcode.com/problems/maximum-depth-of-binary-tree/
