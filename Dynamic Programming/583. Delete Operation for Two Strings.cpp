class Solution {
private:
    int lcs(string a, string b) {
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (a[i - 1] == b[j - 1])    dp[i][j] = 1 + dp[i - 1][j - 1];
                else    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        return dp[m][n];
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        return m + n - 2 * lcs(word1, word2);
    }
};