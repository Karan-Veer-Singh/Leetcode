class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0)
            return false;
        
        int temp = x;
        long long int num = 0;
        
        while(x > 0)
        {
            int d = x % 10;
            num = num*10 + d;
            x /= 10;
        }
        
        return (num == temp);
    }
};

// https://leetcode.com/problems/palindrome-number/submissions/
