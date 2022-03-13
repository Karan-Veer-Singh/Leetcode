// Memoization

class Solution {
public:
    int solve(int i, int tar, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (tar == 0 && nums[i] == 0)    return 2;
            if (tar == 0 || tar == nums[i])  return 1;
            return 0;
        }

        if (dp[i][tar] != -1)    return dp[i][tar];

        int notTake = solve(i - 1, tar, nums, dp);
        int take = 0;
        if (nums[i] <= tar)  take = solve(i - 1, tar - nums[i], nums, dp);

        return dp[i][tar] = (take + notTake);
    }

    int findWays(vector<int> &nums, int tar)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        return solve(n - 1, tar, nums, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        int totalSum = 0;
        for (int i : nums)    totalSum += i;

        if (totalSum - target < 0 || (totalSum - target) % 2)  return 0;
        return findWays(nums, (totalSum - target) / 2);
    }
};

______________________________________________________________________________
// Tabulation

class Solution {
public:
    int findWays(vector<int> &nums, int tar)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

        if (nums[0] == 0)    dp[0][0] = 2;
        else    dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= tar)  dp[0][nums[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int t = 0; t <= tar; t++)
            {
                int notTake = dp[i - 1][t];
                int take = 0;
                if (nums[i] <= t)  take = dp[i - 1][t - nums[i]];

                dp[i][t] = (take + notTake);
            }
        }

        return dp[n - 1][tar];
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        int totalSum = 0;
        for (int i : nums)    totalSum += i;

        if (totalSum - target < 0 || (totalSum - target) % 2)  return 0;
        return findWays(nums, (totalSum - target) / 2);
    }
};

______________________________________________________________________________
// Tabulation (Space Optimized)

class Solution {
public:
    int findWays(vector<int> &nums, int tar)
    {
        int n = nums.size();
        vector<int> prev(tar + 1, 0), curr(tar + 1, 0);

        if (nums[0] == 0)    prev[0] = 2;
        else    prev[0] = 1;

        if (nums[0] != 0 && nums[0] <= tar)  prev[nums[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int t = 0; t <= tar; t++)
            {
                int notTake = prev[t];
                int take = 0;
                if (nums[i] <= t)  take = prev[t - nums[i]];

                curr[t] = (take + notTake);
            }

            prev = curr;
        }

        return prev[tar];
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        int totalSum = 0;
        for (int i : nums)    totalSum += i;

        if (totalSum - target < 0 || (totalSum - target) % 2)  return 0;
        return findWays(nums, (totalSum - target) / 2);
    }
};

// https://leetcode.com/problems/target-sum/submissions/