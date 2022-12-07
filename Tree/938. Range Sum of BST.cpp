class Solution {
public:
    void find(TreeNode* root, int low, int high, int& sum) {
        if (root == NULL) return;
        if (root->val >= low && root->val <= high) sum += root->val;
        find(root->left, low, high, sum);
        find(root->right, low, high, sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        find(root, low, high, sum);
        return sum;
    }
};

// https://leetcode.com/problems/range-sum-of-bst/