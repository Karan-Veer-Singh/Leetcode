class Solution {
public:
    double knightProbability(int n, int k, int sr, int sc) 
    {
        vector<vector<double>>dp(n,vector<double>(n,0.0));
        
        int dr[] = {2, 2, 1, 1, -1, -1, -2, -2};
        int dc[] = {1, -1, 2, -2, 2, -2, 1, -1};
        
        dp[sr][sc] = 1;
        
        for(int steps = 1; steps <= k; steps++)
        {
           vector<vector<double>>dp2(n,vector<double>(n,0.0));
            
            for(int r = 0; r < n; r++)
            {
                for(int c = 0; c < n; c++)
                {
                    if(dp[r][c] != 0)
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            int nr = r + dr[i];
                            int nc = c + dc[i];
                            
                            if(nr >= 0 && nr < n && nc >= 0 && nc < n)
                                dp2[nr][nc] += dp[r][c] / 8.0;
                        }
                    }
                }
            }
            
            dp = dp2;
        }
        
        double ans = 0.0;
        for(auto row: dp) 
            for(double x: row) 
                ans += x;
    
        return ans;
    }
};

// https://leetcode.com/problems/knight-probability-in-chessboard/submissions/
