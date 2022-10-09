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

class BSTIterator
{
	stack<TreeNode*> s;
	bool reverse = true;

	void pushAll(TreeNode *root)
	{
		while (root != NULL)
		{
			s.push(root);
			root = (reverse == true) ? root->right : root->left;
		}
	}

public:
	BSTIterator(TreeNode *root, bool isReverse)
	{
		reverse = isReverse;
		pushAll(root);
	}

	int next()
	{
		TreeNode *temp = s.top();
		s.pop();

		if (reverse == true)
			pushAll(temp->left);
		else
			pushAll(temp->right);

		return temp->val;
	}

	bool hasNext()
	{
		return !s.empty();
	}
};

class Solution {
public:
	bool findTarget(TreeNode* root, int k)
	{
		if (root == NULL)	return 0;

		BSTIterator l(root, false);
		BSTIterator r(root, true);

		int i = l.next();
		int j = r.next();

		while (i < j)
		{
			int sum = i + j;

			if (sum == k)
				return 1;

			else if (sum < k)
				i = l.next();

			else
				j = r.next();
		}

		return 0;
	}
};

------------------------------------------------------------------------------------------------
class Solution {
private:
	vector<int> ans;

	void inorder(TreeNode* &root) {
		if (!root) return;
		inorder(root->left);
		ans.push_back(root->val);
		inorder(root->right);
	}

public:
	bool findTarget(TreeNode* root, int target) {
		inorder(root);

		int start = 0, end = ans.size() - 1;

		while (start < end) {
			if (ans[start] + ans[end] == target)   return true;
			else if (ans[start] + ans[end] < target)  start++;
			else  end--;
		}

		return false;
	}
};

// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
