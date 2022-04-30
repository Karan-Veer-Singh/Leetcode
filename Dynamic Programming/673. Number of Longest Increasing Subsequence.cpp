class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        vector<int> dp(n, 1), count(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                }
                else if (nums[i] > nums[j] && 1 + dp[j] == dp[i])
                {
                    count[i] += count[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int nos = 0;
        for (int i = 0; i < n; i++)
            if (dp[i] == maxi)    nos += count[i];

        return nos;
    }
};

// https://leetcode.com/problems/number-of-longest-increasing-subsequence/