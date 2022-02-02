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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while (!nodesQueue.empty())
        {
            int size = nodesQueue.size();
            vector<int> level(size);
            TreeNode *temp;

            for (int i = 0; i < size; i++)
            {
                temp = nodesQueue.front();
                nodesQueue.pop();

                int index = (leftToRight == true) ? i : size - i - 1;

                level[index] = temp -> val;

                if (temp -> left)	nodesQueue.push(temp -> left);
                if (temp -> right)	nodesQueue.push(temp -> right);
            }

            leftToRight = !leftToRight;
            ans.push_back(level);
        }

        return ans;    
    }
};

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/
