class Solution {
public:
    int gcd(int a, int b)
    {
        if(b == 0)  return a;
        return gcd(b, a%b);
    }
    
    int findGCD(vector<int>& nums) 
    {
        int low = INT_MAX;
        int high = INT_MIN;
        
        for(auto x : nums)
        {
            low = min(low, x);
            high = max(high, x);
        }
        
        return gcd(low, high);
    }
};

// https://leetcode.com/problems/find-greatest-common-divisor-of-array/submissions/
