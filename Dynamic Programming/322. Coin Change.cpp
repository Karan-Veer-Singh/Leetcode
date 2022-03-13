// Memoization

class Solution {
public:
    int solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (amount % coins[i] == 0)  return amount / coins[i];
            else    return 1e9;
        }

        if (dp[i][amount] != -1)     return dp[i][amount];

        int notTake = solve(i - 1, amount, coins, dp);
        int take = 1e9;
        if (coins[i] <= amount)  take = 1 + solve(i, amount - coins[i], coins, dp);

        return dp[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(n - 1, amount, coins, dp);

        if (ans >= 1e9)  return -1;
        else    return ans;
    }
};

_______________________________________________________________________
// Tabulation

class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int i = 0; i <= amount; i++)
            if (i % coins[0] == 0)   dp[0][i] = i / coins[0];
            else    dp[0][i] = 1e9;

        for (int i = 1; i < n; i++)
        {
            for (int t = 0; t <= amount; t++)
            {
                int notTake = dp[i - 1][t];
                int take = 1e9;
                if (coins[i] <= t)  take = 1 + dp[i][t - coins[i]];

                dp[i][t] = min(take, notTake);
            }
        }

        int ans = dp[n - 1][amount];
        if (ans >= 1e9)  return -1;
        return ans;
    }
};

_______________________________________________________________________
// Tabulation (Space Optimized)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        for (int i = 0; i <= amount; i++)
            if (i % coins[0] == 0)   prev[i] = i / coins[0];
            else    prev[i] = 1e9;

        for (int i = 1; i < n; i++)
        {
            for (int t = 0; t <= amount; t++)
            {
                int notTake = prev[t];
                int take = 1e9;
                if (coins[i] <= t)  take = 1 + curr[t - coins[i]];

                curr[t] = min(take, notTake);
            }

            prev = curr;
        }

        int ans = prev[amount];
        if (ans >= 1e9)  return -1;
        return ans;
    }
};

// https://leetcode.com/problems/coin-change/submissions/