// Memoization

class Solution {
public:
    int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp)
    {
        if (i == 0)  return j;
        if (j == 0)  return i;

        if (dp[i][j] != -1)  return dp[i][j];

        if (a[i - 1] == b[j - 1])
        {
            return dp[i][j] = solve(i - 1, j - 1, a, b, dp);
        }

        else
        {
            int insert = solve(i, j - 1, a, b, dp);
            int del = solve(i - 1, j, a, b, dp);
            int update = solve(i - 1, j - 1, a, b, dp);

            return dp[i][j] = 1 + min(insert, min(del, update));
        }
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(n, m, word1, word2, dp);
    }
};


// Tabulation

class Solution {
public:
    int minDistance(string A, string B) {
        int n = A.size();
        int m = B.size();

        int dp[2][m + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0)
                    dp[i % 2][j] = j;

                else if (j == 0)
                    dp[i % 2][j] = i;

                else {
                    if (A[i - 1] == B[j - 1])
                        dp[i % 2][j] = dp[(i - 1) % 2][j - 1];

                    else {
                        int replace = dp[(i - 1) % 2][j - 1];
                        int del = dp[(i - 1) % 2][j];
                        int insert = dp[i % 2][j - 1];

                        dp[i % 2][j] = 1 + min({replace, del, insert});
                    }
                }
            }
        }

        return dp[n % 2][m];
    }
};

// https://leetcode.com/problems/edit-distance/
