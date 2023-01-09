// Recursive
------------------

class Solution {
private:
    void recPreorder(TreeNode *root, vector<int> &preorder) {
        if (root == NULL)    return;
        preorder.push_back(root->val);
        recPreorder(root->left, preorder);
        recPreorder(root->right, preorder);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        recPreorder(root, preorder);
        return preorder;
    }
};

---------------------------------------------------------------------------- -

// Iterative
----------------

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == NULL)   return ans;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            root = s.top();
            s.pop();

            ans.push_back(root -> val);

            if (root -> right)
                s.push(root -> right);

            if (root -> left)
                s.push(root -> left);
        }

        return ans;
    }
};

// https://leetcode.com/problems/binary-tree-preorder-traversal/
