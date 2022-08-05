class Solution {
private:
    int solve(vector<int> &nums, int target, vector<int> &dp) {
        if (dp[target] != -1)    return dp[target];
        int res = 0;
        for (int i : nums)
            if (i <= target)
                res += solve(nums, target - i, dp);

        return dp[target] = res;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        return solve(nums, target, dp);
    }
};

// https://leetcode.com/problems/combination-sum-iv/