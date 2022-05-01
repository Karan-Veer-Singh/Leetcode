class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string x = "", y = "";
        int n = s.size(), m = t.size();

        for (int i = 0; i < n; i++)
            if (s[i] != '#') x += s[i];
            else if (!x.empty()) x.pop_back();

        for (int i = 0; i < m; i++)
            if (t[i] != '#') y += t[i];
            else if (!y.empty()) y.pop_back();

        return (x == y);
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)

-------------------------------------------------------------------------- -
class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        int i = s.size() - 1, j = t.size() - 1, cnts = 0, cntt = 0;
        while (i >= 0 || j >= 0)
        {
            char s_ch = '#';
            while (i >= 0) {
                if (s[i] == '#') {cnts++; i--; continue;}
                if (cnts == 0 && s[i] != '#') {s_ch = s[i]; i--; break;}
                cnts--;
                i--;
            }
            char t_ch = '#';
            while (j >= 0) {
                if (t[j] == '#') {cntt++; j--; continue;}
                if (cntt == 0 && t[j] != '#') {t_ch = t[j]; j--; break;}
                cntt--;
                j--;
            }
            if (s_ch != t_ch)   return false;
        }
        return true;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

// https://leetcode.com/problems/backspace-string-compare/