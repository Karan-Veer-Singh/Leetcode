class Solution {
public:
    static bool compare(string a, string b)
    {
        return (a+b) > (b+a);
    }
    
    string largestNumber(vector<int>& nums) 
    {
        string ans = "";
        int zero = 0;
        vector<string> v;
        
        for(int i : nums){
            if(i == 0)
                zero++;
            
            v.push_back(to_string(i));
        }
        
        if(zero == nums.size())
            return "0";
        
        sort(v.begin(), v.end(), compare);
        
        for(string s : v)
            ans += s;
        
        return ans;
    }
};

// https://leetcode.com/problems/largest-number/submissions/
