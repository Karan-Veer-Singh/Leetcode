class Solution {
public:
    int minDistance(string A, string B) 
    {
        int n = A.size();
        int m = B.size();

        int dp[2][m+1];

        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i == 0)
                    dp[i%2][j] = j;

                else if(j == 0)
                    dp[i%2][j] = i;

                else
                {
                    if(A[i-1] == B[j-1])
                        dp[i%2][j] = dp[(i-1)%2][j-1];

                    else
                    {
                        int replace = dp[(i-1)%2][j-1];
                        int del = dp[(i-1)%2][j];
                        int insert = dp[i%2][j-1];

                        dp[i%2][j] = 1 + min({replace, del, insert});
                    }
                }
            }
        }

        return dp[n%2][m];
    }
};

// https://leetcode.com/problems/edit-distance/submissions/
