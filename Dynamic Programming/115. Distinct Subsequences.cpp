class Solution {
public:
    int numDistinct(string A, string B) 
    {
        int n = A.size();
        int m = B.size();

        unsigned long long int dp[2][m + 1];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;
        dp[1][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (A[i - 1] == B[j - 1])
                    dp[i%2][j] = dp[(i - 1)%2][j - 1] + dp[(i - 1)%2][j];

                else
                    dp[i%2][j] = dp[(i - 1)%2][j];
            }
        }

        return dp[n%2][m];   
    }
};

// https://leetcode.com/problems/distinct-subsequences/submissions/
