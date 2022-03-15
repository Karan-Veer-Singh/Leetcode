class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return 0;

        int t = grid[i][j];
        grid[i][j] = 0;

        int down = dfs(i + 1, j, grid);
        int up = dfs(i - 1, j, grid);
        int right = dfs(i, j + 1, grid);
        int left = dfs(i, j - 1, grid);

        grid[i][j] = t;
        return t + max({down, up, right, left});
    }

    int getMaximumGold(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int maxSum = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] != 0)
                    maxSum = max(maxSum, dfs(i, j, grid));

        return maxSum;
    }
};

// https://leetcode.com/problems/path-with-maximum-gold/submissions/