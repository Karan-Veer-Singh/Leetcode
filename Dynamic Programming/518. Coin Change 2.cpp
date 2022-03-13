// Memoization

class Solution {
public:
    int solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (i == 0)  return (amount % coins[i] == 0);

        if (dp[i][amount] != -1) return dp[i][amount];

        int notTake = solve(i - 1, amount, coins, dp);
        int take = 0;
        if (coins[i] <= amount)  take = solve(i, amount - coins[i], coins, dp);

        return dp[i][amount] = (take + notTake);
    }

    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins, dp);
    }
};

_____________________________________________________________________________
// Tabulation

class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int i = 0; i <= amount; i++)
            dp[0][i] = (i % coins[0] == 0);

        for (int i = 1; i < n; i++)
        {
            for (int tar = 0; tar <= amount; tar++)
            {
                int notTake = dp[i - 1][tar];
                int take = 0;
                if (coins[i] <= tar)  take = dp[i][tar - coins[i]];

                dp[i][tar] = (take + notTake);
            }
        }

        return dp[n - 1][amount];
    }
};

_____________________________________________________________________________
// Tabulation (Space Optimized)

class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        for (int i = 0; i <= amount; i++)
            prev[i] = (i % coins[0] == 0);

        for (int i = 1; i < n; i++)
        {
            for (int tar = 0; tar <= amount; tar++)
            {
                int notTake = prev[tar];
                int take = 0;
                if (coins[i] <= tar)  take = curr[tar - coins[i]];

                curr[tar] = (take + notTake);
            }

            prev = curr;
        }

        return prev[amount];
    }
};

// https://leetcode.com/problems/coin-change-2/submissions/