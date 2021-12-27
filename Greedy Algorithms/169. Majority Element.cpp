class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int ele = 0;
        
        for(auto x : nums)
        {
            if(count == 0)
                ele = x;
            
            if(x == ele)
                count++;
            else
                count--;
        }
        
        return ele;
    }
};

// https://leetcode.com/problems/majority-element/
