class Solution {
private:
    int INF = 1000001;

    int dfs(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int i, int ngbr, int left, vector<vector<vector<int>>> &dp) {
        if (i == m)  return (ngbr == target) ? 0 : INF;
        if (ngbr > target)   return INF;
        if (dp[i][ngbr][left] != -1)   return dp[i][ngbr][left];

        if (houses[i] == 0) {
            int minCost = INF;
            for (int color = 1; color <= n; color++) {
                int newNgbr = ngbr;
                if (color != left)   newNgbr++;
                minCost = min(minCost, cost[i][color - 1] + dfs(houses, cost, m, n, target, i + 1, newNgbr, color, dp));
            }
            return dp[i][ngbr][left] = minCost;
        }

        else {
            int newNgbr = ngbr;
            if (houses[i] != left)   newNgbr++;
            return dp[i][ngbr][left] = dfs(houses, cost, m, n, target, i + 1, newNgbr, houses[i], dp);
        }
    }

public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(target + 1, vector<int>(n + 1, -1)));
        int ans = dfs(houses, cost, m, n, target, 0, 0, 0, dp);
        return (ans < INF) ? ans : -1;
    }
};

// https://leetcode.com/problems/paint-house-iii/