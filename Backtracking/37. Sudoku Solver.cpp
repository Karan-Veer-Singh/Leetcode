class Solution {
public:
    
    bool canPlace(int i, int j, char c, vector<vector<char>> &board)
    {
        for(int row = 0; row < 9; row++)
        {
            if(board[row][j] == c)
                return false;
            
            if(board[i][row] == c)
                return false;
            
            if(board[3 * (i/3) + row/3][3 * (j/3) + row%3] == c)
                return false;
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>> &board)
    {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c = '1'; c <= '9'; c++)
                    {
                        if(canPlace(i, j, c, board))
                        {
                            board[i][j] = c;
                        
                            if(solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);   
    }
};

// https://leetcode.com/problems/sudoku-solver/
