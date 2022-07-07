// Top Down

class Solution {
public:
    bool check(string &a, string &b, string &c, int i, int j, int k, vector<vector<int>> &dp)
    {
        if (k == c.size())
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool one = false, two = false;
        if (i < a.length() && a[i] == c[k])
            one = check(a, b, c, i + 1, j, k + 1, dp);

        if (j < b.length() && b[j] == c[k])
            two = check(a, b, c, i, j + 1, k + 1, dp);

        return dp[i][j] = one || two;
    }

    bool isInterleave(string a, string b, string c)
    {
        if ((a.size() + b.size()) != c.size())
            return false;

        vector<vector<int>>dp(a.size() + 1, vector<int>(b.size() + 1, -1));

        return check(a, b, c, 0, 0, 0, dp);
    }
};



// Bottom Up

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.length(), n = s2.length();

        if (s3.length() != m + n)
            return false;

        bool dp[m + 1][n + 1];
        memset(dp, false, sizeof(dp));

        dp[0][0] = true;

        for (int i = 1; i <= m; i++)
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);

        for (int j = 1; j <= n; j++)
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);


        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] =  (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);


        return dp[m][n];
    }
};

// https://leetcode.com/problems/interleaving-string/