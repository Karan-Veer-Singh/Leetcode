class Solution {
public:
    int countNodes(TreeNode* root) {
        int left = 0, right = 0;
        TreeNode* curr = root;
        while (curr != NULL) {
            left++;
            curr = curr->left;
        }
        curr = root;
        while (curr != NULL) {
            right++;
            curr = curr->right;
        }
        if (left == right)
            return pow(2, left) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// https://leetcode.com/problems/count-complete-tree-nodes/