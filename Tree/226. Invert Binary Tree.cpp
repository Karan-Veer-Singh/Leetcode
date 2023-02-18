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
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == NULL)
            return NULL;

        invertTree(root -> left);
        invertTree(root -> right);

        swap(root -> left, root -> right);

        return root;
    }
};

// Iterative

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
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == NULL)
            return NULL;

        queue<TreeNode*> q;
        q.push(root);

        TreeNode *f;
        while (!q.empty())
        {
            f = q.front();
            q.pop();

            swap(f->left, f->right);

            if (f->left)
                q.push(f->left);

            if (f->right)
                q.push(f->right);
        }

        return root;
    }
};

// https://leetcode.com/problems/invert-binary-tree/
