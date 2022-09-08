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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<TreeNode*> s;
        TreeNode *node = root;

        while (true)
        {
            if (node != NULL)
            {
                s.push(node);
                node = node -> left;
            }
            else
            {
                if (s.empty())
                    break;

                node = s.top();
                s.pop();

                ans.push_back(node -> val);

                node = node -> right;
            }
        }

        return ans;
    }
};
------------------------------------------------------------------------ -

class Solution {
private:
    void recInorder(TreeNode *root, vector<int> &inorder) {
        if (root == NULL)    return;
        recInorder(root->left, inorder);
        inorder.push_back(root->val);
        recInorder(root->right, inorder);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        recInorder(root, inorder);
        return inorder;
    }
};

// https://leetcode.com/problems/binary-tree-inorder-traversal/
