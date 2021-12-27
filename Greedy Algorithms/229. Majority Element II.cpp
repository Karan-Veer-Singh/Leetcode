class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int num1 = -1, num2 = -1, c1 = 0, c2 = 0, len = nums.size();
        
        for(int i = 0; i < len; i++)
        {
            if(nums[i] == num1)
                c1++;
            
            else if(nums[i] == num2)
                c2++;
            
            else if(c1 == 0)
            {
                num1 = nums[i];
                c1 = 1;
            }
            
            else if(c2 == 0)
            {
                num2 = nums[i];
                c2 = 1;
            }
            
            else
            {
                c1--;
                c2--;
            }
        }
        
        c1 = 0;
        c2 = 0;
        
        for(int i = 0; i < len; i++)
        {
            if(nums[i] == num1)
                c1++;
            
            else if(nums[i] == num2)
                c2++;
        }
        
        vector<int> ans;
        
        if(c1 > len/3)
            ans.push_back(num1);
        if(c2 > len/3)
            ans.push_back(num2);
        
        return ans;
    }
};

// https://leetcode.com/problems/majority-element-ii/
