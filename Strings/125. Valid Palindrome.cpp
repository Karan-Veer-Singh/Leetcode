class Solution {
public:
    bool palindrome(string str)
    {
        int i = 0;
        int j = str.length() - 1;

        while (i < j)
        {
            if (str[i++] != str[j--])
                return false;
        }

        return true;
    }

    bool isPalindrome(string A) 
    {
        string B = "";

        for (int i = 0; i < A.length(); i++)
            if ((A[i] >= 'A' && A[i] <= 'Z') || (A[i] >= 'a' && A[i] <= 'z') ||(A[i] >= '0' && A[i] <= '9'))
                B += tolower(A[i]);

        return palindrome(B);    
    }
};

// https://leetcode.com/problems/valid-palindrome/submissions/
