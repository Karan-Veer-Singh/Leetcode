// https://leetcode.com/problems/longest-common-subsequence/submissions/

// TOP-DOWN (Memoizatoin)
// Time Complexity = O(n*m)
// Sapce Complexity = O(n*m) + recursion stack space.
class Solution {
public:
    int dp[1005][1005];
    
    int LCS(string &A, string &B, int n, int m)
    {
        if(n == 0 || m == 0)
            return dp[n][m] = 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(A[n-1] == B[m-1])
            return dp[n][m] = 1 + LCS(A, B, n-1, m-1);
        
            return dp[n][m] = max(LCS(A, B, n-1, m), LCS(A, B, n, m-1));
    }
    
    int longestCommonSubsequence(string A, string B) 
    {
        int n = A.size();
        int m = B.size();
        
        memset(dp, -1, sizeof(dp));
        
        return LCS(A, B, n, m);
    }
};


