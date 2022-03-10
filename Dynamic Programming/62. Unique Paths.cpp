// Memoization

class Solution {
public:
	int findPath(int i, int j, vector<vector<int>> &dp)
	{
		if (i == 0 && j == 0)    return 1;
		if (i < 0 || j < 0)      return 0;

		if (dp[i][j] != -1)      return dp[i][j];

		return dp[i][j] = findPath(i - 1, j, dp) + findPath(i, j - 1, dp);
	}

	int uniquePaths(int m, int n)
	{
		vector<vector<int>> dp(m, vector<int>(n, -1));
		return findPath(m - 1, n - 1, dp);
	}
};


------------------------------------------------------------------------------------
// Tabulation

class Solution {
public:
	int uniquePaths(int m, int n)
	{
		vector<long long int> prev(n, 0);

		for (int i = 0; i < m; i++)
		{
			vector<long long int> curr(n, 0);

			for (int j = 0; j < n; j++)
			{
				if (i == 0 && j == 0)
					curr[j] = 1;
				else
					curr[j] = (i > 0 ? prev[j] : 0) + (j > 0 ? curr[j - 1] : 0);
			}

			prev = curr;
		}

		return prev[n - 1];
	}

};



---------------------------------------------------------------------------------- -
// Maths

class Solution {
public:
	int uniquePaths(int m, int n)
	{
		int N = n + m - 2;
		int r = m - 1;

		double res = 1;

		for (int i = 1; i <= r; i++)
			res = res * (N - r + i) / i;

		return (int)res;
	}
};



// https://leetcode.com/problems/unique-paths/