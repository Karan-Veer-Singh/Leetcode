// Memoization

class Solution {
public:
    int solve(int i, int buy, vector<int> &prices, int n, vector<vector<int>> &dp) {
        if (i >= n)  return 0;
        if (dp[i][buy] != -1)    return dp[i][buy];

        int profit = 0;
        if (buy) {
            int take = -prices[i] + solve(i + 1, 0, prices, n, dp);
            int notTake = solve(i + 1, 1, prices, n, dp);
            profit = max(take, notTake);
        }
        else {
            int sell = prices[i] + solve(i + 2, 1, prices, n, dp);
            int notSell = solve(i + 1, 0, prices, n, dp);
            profit = max(sell, notSell);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, n, dp);
    }
};

----------------------------------------------------------------------------------------------
// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            dp[i][0] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
        }
        return dp[0][1];
    }
};

------------------------------------------------------------------------------------------ -
// Space Optimized

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front1(2, 0);
        vector<int> front2(2, 0);
        vector<int> curr(2, 0);

        for (int i = n - 1; i >= 0; i--) {
            curr[1] = max(-prices[i] + front1[0], front1[1]);
            curr[0] = max(prices[i] + front2[1], front1[0]);

            front2 = front1;
            front1 = curr;
        }
        return curr[1];
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/