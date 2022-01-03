class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int n = s.length();
        int count = 0;

        while(n > 0)
        {
            if(s[--n] != ' ')
                count++;
            else if(count > 0)
                return count;
        }

        return count;   
    }
};

// https://leetcode.com/problems/length-of-last-word/
