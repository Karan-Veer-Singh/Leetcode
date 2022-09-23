class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = ((ans << (1 + int(log2(i)))) % MOD + i) % MOD;

        return ans;
    }
};

// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/