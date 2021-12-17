class Solution {
public:    
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> m;
        int preSum = 0;
        int count = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            preSum += nums[i];
            
            if(preSum == k)
                count++;
            if(m.find(preSum-k) != m.end())
                count += m[preSum-k];
        
            m[preSum]++;
        }
        
        return count;
    }
};

// https://leetcode.com/problems/subarray-sum-equals-k/submissions/
