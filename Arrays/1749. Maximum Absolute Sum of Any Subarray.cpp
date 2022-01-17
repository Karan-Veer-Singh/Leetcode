class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int posSum = 0;
        int negSum = 0;
        int ans = INT_MIN;
        
        for(int i : nums)
        {
            posSum += i;
            negSum += i;
            
            ans = max({ans, posSum, abs(negSum)});
            
            if(posSum < 0)  posSum = 0;
            if(negSum > 0)  negSum = 0;
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/submissions/
