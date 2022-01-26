class Solution {
public:
    bool isMatch(string str, string pat) 
    {
        int n = str.size();
        int m = pat.size();

        if(m == 0)
            return (n == 0);

        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));

        dp[0][0] = true;

        for(int j = 1; j <= m; j++)
            if(pat[j-1] == '*')
                dp[0][j] = dp[0][j-1];

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(pat[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];

                else if(str[i-1] == pat[j-1] || pat[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];

                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];    
    }
};

// https://leetcode.com/problems/wildcard-matching/submissions/
