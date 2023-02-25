class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0], maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            minBuy = min(minBuy, prices[i]);
            int currProfit = prices[i] - minBuy;
            maxProfit = max(maxProfit, currProfit);
        }
        return maxProfit;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/