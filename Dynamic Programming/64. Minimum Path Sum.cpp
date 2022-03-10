// Memoization

class Solution {
public:
    int calcSum(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)    return grid[i][j];
        if (i < 0 || j < 0)      return 1e9;

        if (dp[i][j] != -1)      return dp[i][j];

        int up = grid[i][j] + calcSum(i - 1, j, grid, dp);
        int left = grid[i][j] + calcSum(i, j - 1, grid, dp);

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return calcSum(m - 1, n - 1, grid, dp);
    }
};

// TC -> O(M*N)
// SC -> O(M*N) + Recursion Stack Space

---------------------------------------------------------------------------- -

// Tabulation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];

                else
                {
                    int up = grid[i][j];
                    up += (i > 0) ? dp[i - 1][j] : 1e9;

                    int left = grid[i][j];
                    left += (j > 0) ? dp[i][j - 1] : 1e9;

                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

// TC -> O(M*N)
// SC -> O(M*N)

---------------------------------------------------------------------- -

// Tabulation (Space Optimized)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);

            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    curr[j] = grid[i][j];

                else
                {
                    int up = grid[i][j];
                    up += (i > 0) ? prev[j] : 1e9;

                    int left = grid[i][j];
                    left += (j > 0) ? curr[j - 1] : 1e9;

                    curr[j] = min(up, left);
                }
            }

            prev = curr;
        }

        return prev[n - 1];
    }
};

// TC -> O(M*N)
// SC -> O(N)