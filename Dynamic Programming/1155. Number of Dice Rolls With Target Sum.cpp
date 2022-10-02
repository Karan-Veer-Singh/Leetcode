// Memoization

class Solution {
private:
    const int MOD = 1e9 + 7;

    int solve(int n, int k , int t, vector<vector<int>>&dp) {
        if (n == 0 && t == 0)  return 1;
        if (n < 0 || t < 0)  return 0;
        if (dp[n][t] != -1) return dp[n][t];

        int ans = 0;
        for (int i = 1; i <= k; i++)
            if (t >= i)
                ans = (ans + solve(n - 1, k, t - i , dp)) % MOD;

        return dp[n][t] = ans;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1  , vector<int> (target + 1, -1));
        return solve(n , k , target , dp);
    }
};

--------------------------------------------------------------------------------

// Tabulation

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        int mod = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int l = 1; l <= k; l++)
                    if (l > j)  break;
                    else dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % mod;
            }
        }
        return dp[n][target];
    }
};


// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/