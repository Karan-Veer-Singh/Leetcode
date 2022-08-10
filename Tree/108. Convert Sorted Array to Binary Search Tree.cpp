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

    TreeNode* Convert(vector<int> nums, int start, int end)
    {
        if (start > end) return NULL;

        int mid = start + (end - start) / 2;

        TreeNode *n = new TreeNode(nums[mid]);

        n -> left = Convert(nums, start, mid - 1);
        n -> right = Convert(nums, mid + 1, end);

        return n;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Convert(nums, 0, nums.size() - 1);
    }
};

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/