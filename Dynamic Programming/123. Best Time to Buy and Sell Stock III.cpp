// Memoization

class Solution {
public:
    int solve(int i, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp) {
        if (i == prices.size() || cap == 0)  return 0;
        if (dp[i][buy][cap] != -1)    return dp[i][buy][cap];

        int profit = 0;
        if (buy) {
            int take = -prices[i] + solve(i + 1, 0, cap, prices, dp);
            int notTake = solve(i + 1, 1, cap, prices, dp);
            profit = max(take, notTake);
        }
        else {
            int sell = prices[i] + solve(i + 1, 1, cap - 1, prices, dp);
            int notSell = solve(i + 1, 0, cap, prices, dp);
            profit = max(sell, notSell);
        }

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, dp);
    }
};

----------------------------------------------------------------------------------------------------
// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    int profit = 0;
                    if (buy) {
                        int take = -prices[i] + dp[i + 1][0][cap];
                        int notTake = dp[i + 1][1][cap];
                        profit = max(take, notTake);
                    }
                    else {
                        int sell = prices[i] + dp[i + 1][1][cap - 1];
                        int notSell = dp[i + 1][0][cap];
                        profit = max(sell, notSell);
                    }

                    dp[i][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};

----------------------------------------------------------------------------------------------------
// Space Optimized

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    int profit = 0;
                    if (buy) {
                        int take = -prices[i] + after[0][cap];
                        int notTake = after[1][cap];
                        profit = max(take, notTake);
                    }
                    else {
                        int sell = prices[i] + after[1][cap - 1];
                        int notSell = after[0][cap];
                        profit = max(sell, notSell);
                    }

                    curr[buy][cap] = profit;
                }
            }
            after = curr;
        }

        return after[1][2];
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/