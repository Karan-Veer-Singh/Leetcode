class Solution {
public:
    int solve(vector<int> &arr)
    {
        int n = arr.size();
        
        int prev = arr[0];
        int prev2 = 0;
        
        for(int i = 1; i < n; i++)
        {
            int take = arr[i];
            if(i > 1)
                take += prev2;
            
            int notTake = 0 + prev;
            
            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
    
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        
        if(n == 1)  return nums[0];
        if(n == 2)  return max(nums[0], nums[1]);
        
        vector<int> temp1(nums.begin(), nums.end()-1);
        vector<int> temp2(nums.begin()+1, nums.end());
        
        return max(solve(temp1), solve(temp2));
    }
};

// https://leetcode.com/problems/house-robber-ii/
