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
    TreeNode* buildTreeUtil(int start, int end, int &postIndx, vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &mp) {
        if (start > end) return NULL;

        TreeNode *root = new TreeNode(postorder[postIndx--]);
        int inIndx = mp[root->val];

        root->right = buildTreeUtil(inIndx + 1, end, postIndx, inorder, postorder, mp);
        root->left = buildTreeUtil(start, inIndx - 1, postIndx, inorder, postorder, mp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int start = 0, end = n - 1;

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)  mp[inorder[i]] = i;

        int postIndx = n - 1;

        return buildTreeUtil(start, end, postIndx, inorder, postorder, mp);
    }
};

------------------------------------------------------------------------------------------ -
class Solution {
public:
    TreeNode* build(vector<int> &inOrder, int is, int ie, vector<int> &postOrder,
                    int ps, int pe, unordered_map<int, int> &mp)
    {
        if (ps > pe || is > ie) return NULL;

        TreeNode *root = new TreeNode(postOrder[pe]);

        int ri = mp[postOrder[pe]];
        int numsLeft = ri - is;

        root->left = build(inOrder, is, ri - 1, postOrder, ps, ps + numsLeft - 1, mp);
        root->right = build(inOrder, ri + 1, ie, postOrder, ps + numsLeft, pe - 1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inOrder, vector<int>& postOrder)
    {
        if (inOrder.size() != postOrder.size())
            return NULL;

        unordered_map<int, int> mp;

        for (int i = 0; i < inOrder.size(); i++)
            mp[inOrder[i]] = i;

        int iSize = inOrder.size();
        int pSize = postOrder.size();

        TreeNode *root = build(inOrder, 0, iSize - 1, postOrder, 0, pSize - 1, mp);

        return root;
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
