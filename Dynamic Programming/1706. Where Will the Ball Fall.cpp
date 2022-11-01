class Solution {
private:
    int findBallUtil(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if (j < 0 || j >= grid[0].size())    return -1;

        if (i >= grid.size())  return j;

        if (dp[i][j] != -1)  return dp[i][j];

        if (grid[i][j] == 1) {
            if ((j + 1 < grid[0].size()) && (grid[i][j + 1] == -1)) return dp[i][j] = -1;
            return dp[i][j] =  findBallUtil(i + 1, j + 1, grid, dp);
        }
        else {
            if ((j - 1) >= 0 && grid[i][j - 1] == 1)   return dp[i][j] =  -1;
            return dp[i][j] =  findBallUtil(i + 1, j - 1, grid, dp);
        }
    }

public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<int> ans;
        vector<vector<int>> dp(row, vector<int>(col, -1));

        for (int i = 0; i < col; i++)
            ans.push_back(findBallUtil(0, i, grid, dp));

        return ans;
    }
};

// https://leetcode.com/problems/where-will-the-ball-fall/