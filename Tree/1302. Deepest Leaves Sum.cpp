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

// Using Recursion

class Solution {
    int sum = 0;
    int maxDepth = 0;

    void findSum(TreeNode *node, int currDepth) {
        if (node != NULL) {
            if (currDepth > maxDepth) { sum = 0; maxDepth = currDepth; }
            if (currDepth == maxDepth) { sum += node->val; }
            findSum(node->left, currDepth + 1);
            findSum(node->right, currDepth + 1);
        }
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        findSum(root, 1);
        return sum;
    }
};

// TC - O(N)
------------------------------------------------------------------------

// Using BFS

class Solution {
    int sum;

    void findSum(TreeNode *root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            sum = 0;
            int size = q.size();
            while (size--) {
                TreeNode *front = q.front();
                q.pop();

                sum += front->val;

                if (front->left)     q.push(front->left);
                if (front->right)    q.push(front->right);
            }
        }
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        findSum(root);
        return sum;
    }
};

// TC - O(N)

// https://leetcode.com/problems/deepest-leaves-sum/