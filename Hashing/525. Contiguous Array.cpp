class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int, int> m;
        int sum = 0;
        int maxLen = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            sum += nums[i] == 0 ? -1 : 1;
            
            if(sum == 0)
                maxLen = i+1;
            else if(m.find(sum) != m.end())
                maxLen = max(maxLen, i-m[sum]);
            else
                m[sum] = i;
        }
        
        return maxLen;
    }
};

// https://leetcode.com/problems/contiguous-array/submissions/
