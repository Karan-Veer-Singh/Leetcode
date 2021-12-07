class Solution {
public:
    
    vector<string> generate(int n)
    {
        if(n == 1)
            return {"0", "1"};
        
        vector<string> temp = generate(n-1);
        vector<string> ans;
        
        for(int i = 0; i < temp.size(); i++)
            ans.push_back("0" + temp[i]);
        
        for(int i = temp.size()-1; i >= 0; i--)
            ans.push_back("1" + temp[i]);
        
        return ans;
    }
    
    vector<int> grayCode(int n) 
    {
        vector<string> s = generate(n);
        vector<int> ans;
        
        for(string i : s)
            ans.push_back(stoi(i,0,2));
        
        return ans;
    }
};

// https://leetcode.com/problems/gray-code/submissions/
