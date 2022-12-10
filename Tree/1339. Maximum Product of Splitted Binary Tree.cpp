static int mod = 1e9 + 7;
class Solution {
public:
    long long totalsum = 0, ans = 0;
    int sumundertree(TreeNode* root) {
        if (!root)  return 0;
        long long currentsum = sumundertree(root->left) + sumundertree(root->right) + root->val;
        ans = max(ans, currentsum * (totalsum - currentsum));
        return currentsum;
    }
    int maxProduct(TreeNode* root) {
        totalsum = sumundertree(root);
        sumundertree(root);
        return ans % mod;
    }
};

// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/