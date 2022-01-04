class Solution {
public:
    int myAtoi(string s) 
    {
        long long ans = 0;
        int i = 0;
        int flag = 0;
        int len = s.size();

        while (s[i] == ' ')  i++;

        if (s[i] == '+')
        {
            i++;
        }
        else if (s[i] == '-')
        {
            i++;
            flag = 1;
        }

        while (i < len)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int d = s[i] - '0';

                if ( (ans * 10 + d) > INT_MAX)
                    return flag == 1 ? (INT_MIN) : INT_MAX;

                ans = ans * 10 + d;
            }
            else
                break;

            i++;
        }

        return flag == 1 ? -ans : ans;  
    }
};

// https://leetcode.com/problems/string-to-integer-atoi/submissions/
