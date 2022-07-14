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
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int s, int e, int &i, unordered_map<int, int> &mp) {
        if (s > e)   return NULL;

        TreeNode *root = new TreeNode(preorder[i++]);
        int inIndex = mp[root->val];

        root->left = build(preorder, inorder, s, inIndex - 1, i, mp);
        root->right = build(preorder, inorder, inIndex + 1, e, i, mp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        int i = 0;
        return build(preorder, inorder, 0, inorder.size() - 1, i, mp);
    }
};

----------------------------------------------------------------------------------------
class Solution {
public:
    TreeNode* build(vector<int> &preOrder, int preStart, int preEnd, vector<int> &inOrder,
                    int inStart, int inEnd, unordered_map<int, int> &mp)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(preOrder[preStart]);

        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = build(preOrder, preStart + 1, preStart + numsLeft,
                           inOrder, inStart, inRoot - 1, mp);

        root->right = build(preOrder, preStart + numsLeft + 1, preEnd,
                            inOrder, inRoot + 1, inEnd, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < inOrder.size(); i++)
            mp[inOrder[i]] = i;

        TreeNode *root = build(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1, mp);

        return root;
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
