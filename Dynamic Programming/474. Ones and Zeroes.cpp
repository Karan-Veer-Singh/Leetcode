// Memoization

class Solution {
private:
    int dp[101][101][601];

    vector<int> frequency(string &s) {
        vector<int> count(2);
        for (char c : s)
            count[c - '0']++;

        return count;
    }

    int solve(int index, vector<string> &strs, int zeroes, int ones) {
        if (index == strs.size() || zeroes + ones <= 0)    return 0;
        if (dp[zeroes][ones][index] != -1) return dp[zeroes][ones][index];
        vector<int> count = frequency(strs[index]);
        int take = 0;
        if (zeroes >= count[0] && ones >= count[1])
            take = 1 + solve(index + 1, strs, zeroes - count[0], ones - count[1]);

        int notTake = solve(index + 1, strs, zeroes, ones);

        return dp[zeroes][ones][index] = max(take, notTake);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, strs, m, n);
    }
};

-------------------------------------------------------------------------------- -
// Tabulation

class Solution {
private:
    vector<int> frequency(string &s) {
        vector<int> count(2);
        for (char c : s)
            count[c - '0']++;

        return count;
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (string s : strs) {
            vector<int> count = frequency(s);
            for (int zero = m; zero >= count[0]; zero--)
                for (int one = n; one >= count[1]; one--)
                    dp[zero][one] = max(1 + dp[zero - count[0]][one - count[1]], dp[zero][one]);
        }
        return dp[m][n];
    }
};

// https://leetcode.com/problems/ones-and-zeroes/