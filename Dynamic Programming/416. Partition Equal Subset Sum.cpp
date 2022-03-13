class Solution {
public:
    bool subsetSum(int i, int B, vector<int> &A)
    {
        int n = A.size();
        vector<bool> prev(B + 1, 0), curr(B + 1, 0);

        prev[0] = curr[0] = true;

        if (A[0] <= B)  prev[A[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int target = 1; target <= B; target++)
            {
                bool notTake = prev[target];
                bool take = false;
                if (A[i] <= target)
                    take = prev[target - A[i]];

                curr[target] = take || notTake;
            }

            prev = curr;
        }

        return prev[B];
    }

    bool canPartition(vector<int>& nums)
    {
        int n = nums.size();
        int totalSum = 0;

        for (int i : nums)   totalSum += i;

        if (totalSum % 2)    return false;

        int target = totalSum / 2;

        return subsetSum(n - 1, target, nums);
    }
};

// https://leetcode.com/problems/partition-equal-subset-sum/submissions/