class Solution {
public:
    bool solve(string &s, int indx, unordered_set<string>&st, vector<int> &dp) {
        if (indx == s.size())   return true;

        if (dp[indx] != -1) return dp[indx];

        for (int i = indx; i < s.size(); i++) {
            string t = s.substr(indx, i - indx + 1);
            if ( st.find(t) != st.end() && solve(s, i + 1, st, dp) )
                return dp[i] = 1;
        }

        return dp[indx] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return solve(s, 0, st, dp);
    }
};

// https://leetcode.com/problems/word-break/