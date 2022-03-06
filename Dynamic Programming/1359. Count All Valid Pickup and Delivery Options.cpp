class Solution {
public:
    int countOrders(int n) 
    {
        long dp[501];
        int mod = (int) pow(10,9) + 7;
        
        dp[1] = 1;
        dp[2] = 6;
        
        for(int i = 3; i <= n; i++)
        {
            int no = 2*i-1;
            int p = no * (no+1)/2;
            dp[i] = (dp[i-1] * (p)) % mod;
        }
        
        return (int) dp[n];
    }
};

// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/submissions/
