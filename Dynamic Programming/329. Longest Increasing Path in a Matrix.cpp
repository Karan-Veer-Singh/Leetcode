class Solution {
private:
    vector<vector<int>> dir{{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>> &matrix, int m, int n, int i, int j, vector<vector<int>> &dp) {
        if (dp[i][j] != -1)  return dp[i][j];
        int ans = 0;

        for (vector<int> d : dir) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && y >= 0 && x < m && y < n && matrix[x][y] > matrix[i][j]) {
                ans = max(ans, dfs(matrix, m, n, x, y, dp));
            }
        }
        return dp[i][j] = 1 + ans;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int longestPath = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int path = dfs(matrix, m, n, i, j, dp);
                longestPath = max(longestPath, path);
            }
        }
        return longestPath;
    }
};

// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/