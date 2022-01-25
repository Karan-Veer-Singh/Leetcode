class Solution {
public:
    int distinctSubseqII(string s) 
    {
        const int MOD = 1e9+7;
        int n=s.length();
        
        vector<long long int>dp(n+1,0);
       
        dp[0]=1; // Empty is also a subsequence
        
        unordered_map<char,int>mp;
        
         for(int i = 1; i < dp.size(); i++)
         {    
             char ch = s[i-1];
              
             dp[i] = (2 * dp[i-1]) % MOD; 
             
             if(mp.find(ch) != mp.end())
             {   
                 int j = mp[ch];                  
                 dp[i] = (dp[i]-dp[j-1]) % MOD;   
             }
             
             mp[ch] = i; 
         }
        
         // these are the important edge cases
         if(dp[n]<0) 
             dp[n] += MOD;
        
        return dp[n]-1;  // bcz not including the empty susequence
    }
};

// https://leetcode.com/problems/distinct-subsequences-ii/submissions/
