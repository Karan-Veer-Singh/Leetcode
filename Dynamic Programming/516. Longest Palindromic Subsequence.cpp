class Solution {
public:
    int longestPalindromeSubseq(string a)
    {
        string b = a;
        reverse(b.begin(), b.end());

        int n = a.size();
        int m = b.size();

        int dp[2][m + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i % 2][j] = 0;

                else if (a[i - 1] == b[j - 1])
                    dp[i % 2][j] = 1 + dp[(i - 1) % 2][j - 1];

                else
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
            }
        }

        return dp[n % 2][m];
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string A)
    {
        string B = A;
        reverse(B.begin(), B.end());

        int m = A.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (A[i - 1] == B[j - 1])
                    curr[j] = 1 + prev[j - 1];

                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }

            prev = curr;
        }

        return prev[m];
    }
};


// https://leetcode.com/problems/longest-palindromic-subsequence/
