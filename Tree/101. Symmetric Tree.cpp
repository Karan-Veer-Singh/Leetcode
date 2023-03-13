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
    bool isSymmetric(TreeNode* root)
    {
        if (root == NULL)
            return true;

        queue<TreeNode*> q;

        q.push(root -> left);
        q.push(root -> right);

        TreeNode *leftNode, *rightNode;

        while (!q.empty())
        {
            leftNode = q.front();
            q.pop();

            rightNode = q.front();
            q.pop();

            if (leftNode == NULL && rightNode == NULL)
                continue;

            if (leftNode == NULL || rightNode == NULL || leftNode -> val != rightNode -> val)
                return false;

            q.push(leftNode -> left);   q.push(rightNode -> right);
            q.push(leftNode -> right);  q.push(rightNode -> left);
        }

        return true;
    }
};

----------------------------------------------------------------------------------

class Solution {
private:
    bool check(TreeNode *a, TreeNode *b) {
        if (a == NULL || b == NULL) return a == b;
        return (a->val == b->val) && check(a->left, b->right) && check(a->right, b->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)    return true;
        return check(root->left, root->right);
    }
};

// https://leetcode.com/problems/symmetric-tree/
