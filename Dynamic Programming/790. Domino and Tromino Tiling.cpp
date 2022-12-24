class Solution {
public:
    int numTilings(int n) {
        if (n <= 1)  return 1;

        long long mod = 1e9 + 7;

        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = ((2 % mod * dp[i - 1] % mod) % mod + dp[i - 3] % mod) % mod;
        }

        return dp[n];
    }
};

// https://leetcode.com/problems/domino-and-tromino-tiling/