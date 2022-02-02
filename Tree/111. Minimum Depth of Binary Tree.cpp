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
    int minDepth(TreeNode* root) 
    {
        if (root == NULL)
		    return 0;
        
        if(root -> left == NULL && root -> right == NULL)
            return 1;
        
        int lh = (root -> left) ? minDepth(root -> left) : INT_MAX;
        int rh = (root -> right) ? minDepth(root -> right) : INT_MAX;

        return 1 + min(lh, rh);    
    }
};


// Iterative

class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        if (root == NULL)
		    return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int depth = 1;
        
        while(!q.empty())
        {
            int size = q.size();
            TreeNode *temp;
            
            while(size--)
            {
                temp = q.front();
                q.pop();
                
                if(temp -> left == NULL && temp -> right == NULL)
                    return depth;
                
                if(temp -> left)    q.push(temp -> left);
                if(temp -> right)   q.push(temp -> right);
            }
            
            depth++;
        }
        
        return depth;
    }
};

// https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/
