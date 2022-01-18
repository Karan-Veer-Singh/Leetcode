class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); 
        int res = nums[0];
        int left = 1, right = 1;
        
        for (int i = 0; i < n; i++) {
            left *= nums[i];
            right *=  nums[n - 1 - i];
            
            res = max({res, left, right});
            
            if(left==0)     left = 1;
            if(right==0)    right = 1;
        }
        
        return res;
    }
};

// https://leetcode.com/problems/maximum-product-subarray/submissions/
