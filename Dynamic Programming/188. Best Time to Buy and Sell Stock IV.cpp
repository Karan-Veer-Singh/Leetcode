// Memoization

class Solution {
public:
	int solve(int i, int tranNo, vector<int> &prices, int k, vector<vector<int>> &dp) {
		if (i == prices.size() || tranNo == 2 * k) return 0;
		if (dp[i][tranNo] != -1)    return dp[i][tranNo];

		int profit = 0;
		if (tranNo % 2 == 0) { // buy
			int take = -prices[i] + solve(i + 1, tranNo + 1, prices, k, dp);
			int notTake = solve(i + 1, tranNo, prices, k, dp);
			profit = max(take, notTake);
		}
		else {  // sell
			int sell = prices[i] + solve(i + 1, tranNo + 1, prices, k, dp);
			int notSell = solve(i + 1, tranNo, prices, k, dp);
			profit = max(sell, notSell);
		}

		return dp[i][tranNo] = profit;
	}

	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2 * k, -1));
		return solve(0, 0, prices, k, dp);
	}
};

------------------------------------------------------------------------------------------
// Tabulation

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

		for (int i = n - 1; i >= 0; i--) {
			for (int tranNo = 2 * k - 1; tranNo >= 0; tranNo--) {
				int profit = 0;
				if (tranNo % 2 == 0) { // buy
					int take = -prices[i] + dp[i + 1][tranNo + 1];
					int notTake = dp[i + 1][tranNo];
					profit = max(take, notTake);
				}
				else {  // sell
					int sell = prices[i] + dp[i + 1][tranNo + 1];
					int notSell = dp[i + 1][tranNo];
					profit = max(sell, notSell);
				}

				dp[i][tranNo] = profit;
			}
		}

		return dp[0][0];
	}
};

----------------------------------------------------------------------------------------------
// Space Optimized

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		vector<int> after(2 * k + 1, 0);
		vector<int> curr(2 * k + 1, 0);

		for (int i = n - 1; i >= 0; i--) {
			for (int tranNo = 2 * k - 1; tranNo >= 0; tranNo--) {
				int profit = 0;
				if (tranNo % 2 == 0) { // buy
					int take = -prices[i] + after[tranNo + 1];
					int notTake = after[tranNo];
					profit = max(take, notTake);
				}
				else {  // sell
					int sell = prices[i] + after[tranNo + 1];
					int notSell = after[tranNo];
					profit = max(sell, notSell);
				}

				curr[tranNo] = profit;
			}
			after = curr;
		}

		return after[0];
	}
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/