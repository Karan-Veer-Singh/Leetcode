// Memoization

class Solution {
private:
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if (i > j)   return 0;
        if (dp[i][j] != -1)  return dp[i][j];
        int mini = INT_MAX;

        for (int indx = i; indx <= j; indx++) {
            int cost = cuts[j + 1] - cuts[i - 1] + solve(i, indx - 1, cuts, dp) +
                       solve(indx + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return solve(1, c, cuts, dp);
    }
};

------------------------------------------------------------------------------------ -
// Tabulation

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for (int i = c; i >= 1; i--) {
            for (int j = 1; j <= c; j++) {
                if (i > j)   continue;
                int mini = INT_MAX;

                for (int indx = i; indx <= j; indx++) {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][indx - 1] + dp[indx + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }
};

// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/