class Solution {
public:
    
    void generate(int index, string s, vector<string> &ans, int n, int open, int close)
    {
        if(index == 2*n)
        {
            ans.push_back(s);
            return;
        }
        
        if(open < n)
            generate(index+1, s+'(', ans, n, open+1, close);

        
        if(close < open)
            generate(index+1, s+')', ans, n, open, close+1);
        
        
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        string s;
        generate(0, s, ans, n, 0, 0);
        
        return ans;
    }
};

// https://leetcode.com/problems/generate-parentheses/submissions/
