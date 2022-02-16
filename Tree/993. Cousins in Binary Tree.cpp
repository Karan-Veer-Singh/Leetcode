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
    bool isCousins(TreeNode* root, int x, int y) 
    {
        if(root == NULL)    return false;

        queue<TreeNode*> q;
        q.push(root);
       
        TreeNode *temp;
        while(!q.empty())
        {
            int size = q.size();
            int count = 0;
            while(size--)
            {
                temp = q.front();
                q.pop();

                if(temp->val == x || temp->val == y)
                    count++;
                
                if(temp->left && temp->right)
                    if( (temp->left->val == x && temp->right->val == y) || (temp->left->val == y && temp->right->val == x) )
                        return false;
                
                if(temp->left)      q.push(temp->left);
                if(temp->right)     q.push(temp->right);
            }

            if(count == 2)  return true;
        }   

        return false;
    }
};

// https://leetcode.com/problems/cousins-in-binary-tree/submissions/
