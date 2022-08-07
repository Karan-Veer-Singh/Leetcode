class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>>dp(n, vector<long long>(5, 1));
        int MOD = 1000000007;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][1]; //ea
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD; //ae, ie
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4]) % MOD; //ai, ei, oi, ui
            dp[i][3] = (dp[i - 1][2] + dp[i - 1][4]) % MOD; //io, uo
            dp[i][4] = dp[i - 1][0] ;//au
        }
        long long sum = 0;
        for (int i = 0; i < 5; i++) sum  = (sum + dp[n - 1][i]) % MOD;
        return sum;
    }
};
------------------------------------------------------------------------ -

class Solution {
public:
    int countVowelPermutation(int n) {
        long a = 1, e = 1, i = 1, o = 1, u = 1, mod = pow(10, 9) + 7;
        long a2, e2, i2, o2, u2;

        for (int j = 2; j <= n; j++) {
            a2 = (e + i + u) % mod;
            e2 = (a + i) % mod;
            i2 = (e + o) % mod;
            o2 = i;
            u2 = (o + i) % mod;

            a = a2, e = e2, i = i2, o = o2, u = u2;
        }

        return (a + e + i + o + u) % mod;
    }
};

// https://leetcode.com/problems/count-vowels-permutation/