class Solution {
public:
    vector<string> ans;
    unordered_map<string, int> m;
    
    void generate(string s, int min_rem)
    {
        if(m[s] != 0)
            return;
        else
            m[s]++;
        
        if(min_rem == 0)
        {
            int valid = minRemoval(s);
            if(valid == 0)
                ans.push_back(s);
            
            return;
        }
      
        for(int i = 0; i < s.size(); i++)
        {
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            generate(left + right, min_rem-1);
        }
    }
    
    int minRemoval(string s)
    {
        stack<char> stk;
        for(int i = 0; i < s.size(); i++)
        {
           if(s[i] == '(')
                stk.push('(');
            
            else if(s[i] == ')')
            {
                if(!stk.empty() && stk.top() == '(')
                    stk.pop();
                else
                    stk.push(')');
            }
        }
        
        return stk.size();
    }
    
    vector<string> removeInvalidParentheses(string s) 
    {
        generate(s, minRemoval(s));   
        return ans;
    }
};

// https://leetcode.com/problems/remove-invalid-parentheses/submissions/
