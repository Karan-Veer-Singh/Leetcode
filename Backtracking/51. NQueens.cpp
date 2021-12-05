class Solution {
public:
    
    bool isSafe(vector<string> board, int i, int j, int n)
    {
        for(int row = 0; row < i; row++)
            if(board[row][j] == 'Q')
                return false;
        
        int x = i;
        int y = j;
        
        while(x >= 0 && y >= 0)
        {
            if(board[x][y] == 'Q')
                return false;
            
            x--;
            y--;
        }
        
        x = i;
        y = j;
        
        while(x >= 0 && y < n)
        {
            if(board[x][y] == 'Q')
                return false;
            
            x--;
            y++;
        }
        
        return true;
    }
    
    void queens(vector<vector<string>> &ans, vector<string> &board, int i, int n)
    {
        if(i == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int j = 0; j < n; j++)
        {
            if(isSafe(board,i,j,n))
            {
                board[i][j] = 'Q';
                queens(ans, board, i+1, n);
                board[i][j] = '.';
            }
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i = 0; i < n; i++)
            board[i] = s;
        
        queens(ans,board,0,n);
        
        return ans;
    }
};

// https://leetcode.com/problems/n-queens/
