class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        int n = 10001;
        
        if(nums.size() == 1)
            return nums[0];
        
        vector<int> map(n, 0);
        
        int mx = INT_MIN;
        
        for(int x : nums)
        {
            map[x] += x;
            mx = max(mx, x);
        }
        
        int a = map[0];
        int b = max(a, map[1]);
        
        for(int i = 2; i <= mx; i++)
        {
            int curr = max(map[i] + a, b);
            a = b;
            b = curr;
        }
        
        return b;
    }
};

// https://leetcode.com/problems/delete-and-earn/submissions/
