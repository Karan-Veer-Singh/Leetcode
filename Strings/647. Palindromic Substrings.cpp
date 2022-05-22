// DP

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)  dp[i][j] = 1;
                else if (j == i + 1 && s[i] == s[j])   dp[i][j] = 1;
                else if (s[i] == s[j])   dp[i][j] = dp[i + 1][j - 1];
                res += dp[i][j];
            }
        }
        return res;
    }
};

TC - O(N ^ 2);
SC - O(N ^ 2);

--------------------------------------------------------------------------------
// Two Pointer

class Solution {
    int isPalindrome(int i, int j, string &s) {
        int count = 0;
        while (i >= 0 && j < s.length() && s[i--] == s[j++])
            count++;

        return count;
    }

public:
    int countSubstrings(string s) {
        int n = s.length(), res = 0;
        for (int i = 0; i < n; i++) {
            res += isPalindrome(i, i, s);
            res += isPalindrome(i, i + 1, s);
        }
        return res;
    }
};

TC - O(N ^ 2);
SC - O(1);

// https://leetcode.com/problems/palindromic-substrings/