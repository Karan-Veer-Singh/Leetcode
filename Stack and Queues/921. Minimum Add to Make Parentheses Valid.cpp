class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int open = 0, close = 0;
        
        for(int i = 0; s[i]; i++)
        {
            open += s[i] == '(' ? 1 : -1;
            
            if(open == -1)
            {
                close++;
                open = 0;
            }
        }
        
        return open+close;
    }
};

// 	https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/
