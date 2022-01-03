class Solution {
public:
    bool isNumber(string s) 
    {
        bool num = false;
        bool exp = false;
        bool dot = false;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = true;
            } else if (c == 'e' || c == 'E') {
                if (exp || !num)
                    return false;
                exp = true;
                num = false;
            } else if (c == '.') {
                if (dot || exp)
                    return false;
                dot = true;
            } else if (c == '-' || c == '+') {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            } else {
                return false;
            }
        }

        return num;    
    }
};

// https://leetcode.com/problems/valid-number/submissions/
