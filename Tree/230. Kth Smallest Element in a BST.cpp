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
    int kthSmallest(TreeNode* root, int k) 
    {
        stack<TreeNode*> s;
        int c = 0;

        while(true)
        {
            if(root != NULL)    
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                if(s.empty())   break;

                root = s.top();
                s.pop();

                c++;
                if(c == k)      return root->val;

                root = root->right;
            }
        }

        return -1;
    }
};

//	https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/ 
