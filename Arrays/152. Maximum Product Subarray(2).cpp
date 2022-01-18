class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxProd = nums[0];
        int maxi = nums[0];
        int mini = nums[0];
        
        for(int i=1; i<nums.size(); i++)
		{ 
            int temp = max({nums[i], nums[i]*maxi, nums[i]*mini});
            mini = min({nums[i], nums[i]*maxi, nums[i]*mini});
            
            maxi = temp;
            
            maxProd = max(maxProd, maxi);
        }
        
        return maxProd;
    }
};

// https://leetcode.com/problems/maximum-product-subarray/submissions/
