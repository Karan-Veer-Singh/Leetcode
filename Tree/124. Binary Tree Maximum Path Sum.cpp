class Solution {
private:
    int maxPathSumUtil(TreeNode *node, int &maxSum) {
        if (node == NULL)    return 0;

        int leftmaxSum = max(0, maxPathSumUtil(node->left, maxSum));
        int rightmaxSum = max(0, maxPathSumUtil(node->right, maxSum));

        maxSum = max(maxSum, (node->val + leftmaxSum + rightmaxSum));

        return node->val + max(leftmaxSum, rightmaxSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumUtil(root, maxSum);
        return maxSum;
    }
};

// https://leetcode.com/problems/binary-tree-maximum-path-sum/