class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int n = nums.size();
       
        if(n < 3)
            return 0;
        
        int dp = 0;
        int ans = 0;
        
        for(int i = 2; i < n; i++)
        {
            if(nums[i] - nums[i-1] == nums[i-1]-nums[i-2])
            {
                dp = 1 + dp;
                ans += dp;
            }
            else
            {
                dp = 0;
            }
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/arithmetic-slices/submissions/
