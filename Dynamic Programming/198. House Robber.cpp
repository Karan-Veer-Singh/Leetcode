class Solution {
private:
    int totalMoney(int indx, vector<int> &nums, vector<int> &dp) {
        if (indx < 0) return 0;

        if (dp[indx] != -1)  return dp[indx];

        int take = nums[indx] + totalMoney(indx - 2, nums, dp);
        int notTake = 0 + totalMoney(indx - 1, nums, dp);

        return dp[indx] = max(take, notTake);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return totalMoney(n - 1, nums, dp);
    }
};

----------------------------------------------------------------

class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();

        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
                take += prev2;

            int notTake = 0 + prev;

            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

// https://leetcode.com/problems/house-robber/
