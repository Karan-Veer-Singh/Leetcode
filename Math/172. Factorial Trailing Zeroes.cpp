class Solution {
public:
    int trailingZeroes(int n) 
    {
        int ans = 0;
        
        while(n)
        {
            n /= 5;
            ans += n;
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/factorial-trailing-zeroes/submissions/
