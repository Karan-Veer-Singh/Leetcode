// Memoization

class Solution {
public:
	int findPath(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
	{
		if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)   return 0;
		if (i == 0 && j == 0)    return 1;
		if (i < 0 || j < 0)      return 0;

		if (dp[i][j] != -1)      return dp[i][j];

		return dp[i][j] = findPath(i - 1, j, obstacleGrid, dp) + findPath(i, j - 1, obstacleGrid, dp);
	}

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		vector<vector<int>> dp(m, vector<int>(n, -1));
		return findPath(m - 1, n - 1, obstacleGrid, dp);
	}
};


------------------------------------------------------------------------------------
// Tabulation

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		vector<long long int> prev(n, 0);

		for (int i = 0; i < m; i++)
		{
			vector<long long int> curr(n, 0);

			for (int j = 0; j < n; j++)
			{
				if (obstacleGrid[i][j] == 1)
					curr[j] = 0;

				else if (i == 0 && j == 0)
					curr[j] = 1;

				else
					curr[j] = (i > 0 ? prev[j] : 0) + (j > 0 ? curr[j - 1] : 0);
			}

			prev = curr;
		}

		return prev[n - 1];
	}
};


// https://leetcode.com/problems/unique-paths-ii/submissions/