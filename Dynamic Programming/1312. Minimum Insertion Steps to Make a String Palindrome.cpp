class Solution {
public:
	int lcs(string &a, string &b)
	{
		int n = a.size();
		int m = b.size();

		vector<int> prev(m + 1, 0), curr(m + 1, 0);

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (a[i - 1] == b[j - 1])
					curr[j] = 1 + prev[j - 1];
				else
					curr[j] = max(prev[j], curr[j - 1]);
			}

			prev = curr;
		}

		return prev[m];
	}

	int minInsertions(string s)
	{
		string p = s;
		reverse(p.begin(), p.end());

		return s.size() - lcs(s, p);
	}
};

// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/