class Solution {
public:
    string reverseWords(string s) 
    {
        int i = s.length()-1;
        string ans = "";
        
        while(i >= 0)
        {
            while(i >= 0 && s[i] == ' ')  i--;
            int j = i;
            
            if(i < 0)   break;
            
            while(i >= 0 && s[i] != ' ')  i--;
            
            string word = s.substr(i+1, j-i);
        
            if(ans.empty())     
                ans += word; 
            else                
                ans += " " + word;
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/reverse-words-in-a-string/submissions/
