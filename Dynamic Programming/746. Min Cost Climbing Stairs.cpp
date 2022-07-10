// Memoization

class Solution {
private:
    int solve(vector<int> &cost, int n, vector<int> &dp) {
        if (n == 0)  return cost[0];
        if (n == 1)  return cost[1];

        if (dp[n] != -1) return dp[n];

        return dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    }
};

_________________________________________________________________________

// Tabulation

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();

        vector<int> dp(n, 0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);

        return min(dp[n - 1], dp[n - 2]);
    }
};

// TC - O(N)
// SC - O(N)

_______________________________________________________________


// Space Optimized
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();

        int a = cost[0];
        int b = cost[1];

        for (int i = 2; i < n; i++)
        {
            int c = cost[i] + min(a, b);
            a = b;
            b = c;
        }

        return min(a, b);
    }
};

// TC - O(N)
// SC - O(1)


// https://leetcode.com/problems/min-cost-climbing-stairs/