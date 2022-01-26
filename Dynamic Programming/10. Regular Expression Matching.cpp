class Solution {
public:
    bool isMatch(string str, string pat) 
    {
        int n = pat.size();
        int m = str.size();

        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));
        
        dp[0][0] = true;

        for(int i = 1; i <= n; i++)
            if(pat[i-1] == '*')
                dp[i][0] = dp[i-2][0];
       

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                char pc = pat[i-1];
                char sc = str[j-1];

                if(pc == '*'){
                    if(pat[i-2] == '.' || pat[i-2] == sc)
                        dp[i][j] = dp[i-2][j] || dp[i][j-1];
                    else
                        dp[i][j] = dp[i-2][j];
                }

                else if(pc == '.' || pc == sc)
                    dp[i][j] = dp[i-1][j-1];

            }
        }

        return dp[n][m];    
    }
};

// https://leetcode.com/problems/regular-expression-matching/
