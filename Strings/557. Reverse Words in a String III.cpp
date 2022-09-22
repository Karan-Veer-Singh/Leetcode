class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == ' ')
            {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        reverse(s.begin() + i, s.end());
        return s;
    }
};

// https://leetcode.com/problems/reverse-words-in-a-string-iii/