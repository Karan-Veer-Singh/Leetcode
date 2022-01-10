class Solution {
public:
    int romanToInt(string A) 
    {
        map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int n = A.length();
        int ans;

        ans = roman[A[n-1]];
    
        for(int i = n-2; i >= 0; i--)
            if(roman[A[i]] < roman[A[i+1]])
                ans -= roman[A[i]];
            else
                ans += roman[A[i]];

        return ans;
    }
};

// https://leetcode.com/problems/roman-to-integer/submissions/
