// Memoization

class Solution {
public:
    int solve(int i, int buy, vector<int> &prices, int n, vector<vector<int>> &dp) {
        if (i == n)  return 0;
        if (dp[i][buy] != -1)    return dp[i][buy];

        int profit = 0;
        if (buy) {
            int take = -prices[i] + solve(i + 1, 0, prices, n, dp);
            int notTake = solve(i + 1, 1, prices, n, dp);
            profit = max(take, notTake);
        }
        else {
            int sell = prices[i] + solve(i + 1, 1, prices, n, dp);
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
----------------------------------------------------------------------------

// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    int take = -prices[i] + dp[i + 1][0];
                    int notTake = dp[i + 1][1];
                    profit = max(take, notTake);
                }
                else {
                    int sell = prices[i] + dp[i + 1][1];
                    int notSell = dp[i + 1][0];
                    profit = max(sell, notSell);
                }

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }
};

------------------------------------------------------------------------
// Space Optimized

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int aheadBuy, aheadNotBuy, currBuy, currNotBuy;
        aheadNotBuy = aheadBuy = 0;

        for (int i = n - 1; i >= 0; i--) {
            currNotBuy = max(prices[i] + aheadBuy, aheadNotBuy);
            currBuy = max(-prices[i] + aheadNotBuy, aheadBuy);

            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

        return aheadBuy;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/