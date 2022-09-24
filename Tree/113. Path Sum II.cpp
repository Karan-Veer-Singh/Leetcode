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
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, int target) {
        if (!root) return;

        target -= root->val;
        path.push_back(root->val);

        if (target == 0 && !root->left && !root->right)
            ans.push_back(path);

        dfs(root->left,  target);
        dfs(root->right, target);

        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};

// https://leetcode.com/problems/path-sum-ii/