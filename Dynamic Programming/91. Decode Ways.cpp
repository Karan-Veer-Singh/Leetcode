class Solution {
private:
    int nWays(int i, string &s, vector<int> &dp) {
        if (i >= s.size())   return 1;
        if (s[i] == '0')     return 0;
        if (i == s.size() - 1) return 1;
        if (dp[i] != -1)     return dp[i];

        if (s[i] == '1' || (s[i] == '2' && (s[i + 1] >= '0' && s[i + 1] <= '6')))
            return dp[i] = nWays(i + 1, s, dp) + nWays(i + 2, s, dp);
        else
            return dp[i] = nWays(i + 1, s, dp);
    }

public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return nWays(0, s, dp);
    }
};

// https://leetcode.com/problems/decode-ways/