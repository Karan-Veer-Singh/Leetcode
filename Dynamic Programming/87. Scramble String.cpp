class Solution {
public:
    unordered_map<string, bool> m;
    bool isScramble(string A, string B)
    {
        if (A.length() != B.length())
            return false;

        int n = A.length();

        if (n == 0)
            return true;

        if (A == B)
            return true;

        string ta = A;
        string tb = B;

        sort(ta.begin(), ta.end());
        sort(tb.begin(), tb.end());

        if (ta != tb)
            return false;

        string key = A + " " + B;

        if (m.find(key) != m.end())
            return m[key];

        for (int i = 1; i < n; i++)
        {
            if (isScramble(A.substr(0, i), B.substr(0, i)) && isScramble(A.substr(i, n - i), B.substr(i, n - i)))
                return m[key] = true;

            if (isScramble(A.substr(0, i), B.substr(n - i, i)) && isScramble(A.substr(i, n - i), B.substr(0, n - i)))
                return m[key] = true;
        }

        return m[key] = false;
    }
};

// https://leetcode.com/problems/scramble-string/
