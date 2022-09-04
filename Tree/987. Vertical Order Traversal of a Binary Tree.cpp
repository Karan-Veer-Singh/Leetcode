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
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        vector<vector<int>> ans;

        if (root == NULL)    return ans;

        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode*, pair<int, int>>> q;

        int dist = 0, level = 0;
        q.push({root, {dist, level}});

        pair<TreeNode*, pair<int, int>> temp;
        TreeNode* node;

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            node = temp.first;
            dist = temp.second.first;
            level = temp.second.second;

            m[dist][level].insert(node->val);

            if (node->left)
                q.push({node->left, {dist - 1, level + 1}});

            if (node->right)
                q.push({node->right, {dist + 1, level + 1}});
        }

        for (auto p : m)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }

            ans.push_back(col);
        }

        return ans;
    }
};

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
