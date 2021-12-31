class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int missing = 0;
        
        for(int i = 0; i < 32; i++)
        {
            int count = 0;
            for(int n : nums)
            {
                int mask = 1 << i;
                if(n & mask)
                    count++;
            }
            
            count %= 3;
            missing = missing|(count << i);
        }
        
        return missing;
    }
};

// https://leetcode.com/problems/single-number-ii/
