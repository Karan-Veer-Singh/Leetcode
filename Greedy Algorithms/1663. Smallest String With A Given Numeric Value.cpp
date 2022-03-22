class Solution {
public:
	string getSmallestString(int n, int k) {
		string ans(n, ' ');

		for (int i = n - 1; i >= 0; i--) {
			int val = min(26, k - i);
			ans[i] = char('a' + val - 1);
			k -= val;
		}

		return ans;
	}
};

// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/submissions/