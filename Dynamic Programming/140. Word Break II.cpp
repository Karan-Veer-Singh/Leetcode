class Solution {
public:
    vector<string> solve(string s, vector<string> &wordDict,  unordered_map<string, vector<string>> &dp) {
        if (dp.find(s) != dp.end())  return dp[s];
        vector<string> result;
        for (string w : wordDict) {
            if (s.substr(0, w.length()) == w) {
                if (w.length() == s.length()) {
                    result.push_back(w);
                }
                else {
                    vector<string> temp = solve(s.substr(w.length()), wordDict, dp);
                    for (string t : temp)
                        result.push_back(w + " " + t);
                }
            }
        }
        return dp[s] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> dp;
        solve(s, wordDict, dp);
        return dp[s];
    }
};

// https://leetcode.com/problems/word-break-ii/submissions/