class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;

        for (int num : nums)
            if (num % 2 == 0)
                sum += num;

        for (auto v : queries) {
            int value = v[0];
            int index = v[1];

            if (nums[index] % 2 == 0)
                sum -= nums[index];

            nums[index] += value;

            if (nums[index] % 2 == 0)
                sum += nums[index];

            ans.push_back(sum);
        }
        return ans;
    }
};

// https://leetcode.com/problems/sum-of-even-numbers-after-queries/