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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)   return ans;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        bool leftToRight = true;

        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> level(size, 0);

            for (int i = 0; i < size; i++) {
                TreeNode *f = nodesQueue.front();
                nodesQueue.pop();

                int indx = (leftToRight) ? i : size - i - 1;
                level[indx] = f->val;

                if (f->left != NULL)     nodesQueue.push(f->left);
                if (f->right != NULL)    nodesQueue.push(f->right);
            }

            leftToRight = !leftToRight;
            ans.push_back(level);
        }

        return ans;
    }
};

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/