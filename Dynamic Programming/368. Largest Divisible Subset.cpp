class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = 1, lastIndex = 0;
        int n = nums.size();
        vector<int> dp(n, 1), path(n);

        for (int i = 0; i < n; i++) {
            path[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if ((nums[i] % nums[prev] == 0) && (1 + dp[prev] > dp[i])) {
                    dp[i] = 1 + dp[prev];
                    path[i] = prev;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> lds;
        lds.push_back(nums[lastIndex]);
        while (path[lastIndex] != lastIndex) {
            lastIndex = path[lastIndex];
            lds.push_back(nums[lastIndex]);
        }

        return lds;
    }
};