class Solution {
public:
    string reverseWords(string s) {
        int i = s.size() - 1;
        string ans = "";

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ')    i--;
            int j = i;

            if (i < 0)   break;

            while (i >= 0 && s[i] != ' ')    i--;

            string temp = s.substr(i + 1, j - i);

            if (ans.size() == 0)
                ans += temp;
            else
                ans = ans + " " + temp;
        }

        return ans;
    }
};

// https://leetcode.com/problems/reverse-words-in-a-string/
