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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == NULL || q == NULL)
            return p == q;
        
        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};



// Iterative

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
    bool isSameTree(TreeNode* root1, TreeNode* root2) 
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        
        queue<TreeNode*> q;
        
        q.push(root1);
        q.push(root2);
        
        TreeNode *temp1, *temp2;
        
        while(!q.empty())
        {
            temp1 = q.front();
            q.pop();
            
            temp2 = q.front();
            q.pop();
            
            if(temp1 == NULL && temp2 == NULL)
                continue;
            
            if(temp1 == NULL || temp2 == NULL || temp1->val != temp2->val)
                return false;
            
            q.push(temp1 -> left);  q.push(temp2 -> left);
            q.push(temp1 -> right); q.push(temp2 -> right);
        }
        
        return true;
    }
};

// https://leetcode.com/problems/same-tree/submissions/
