class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int j = -1;
        int zeroes = 0;
        int maxLen = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                zeroes++;
            
            while(zeroes > k)
            {
                j++;
                if(nums[j] == 0)
                    zeroes--;
            }
            
            int len = i-j;
            maxLen = max(maxLen, len);
        }
        
        return maxLen;
    }
};

// https://leetcode.com/problems/max-consecutive-ones-iii/
