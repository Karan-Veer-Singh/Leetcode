class Solution {
public:
    bool isValid(string s) {
        if (s[0] == '0')
            return false;

        int val = stoi(s);
        return val <= 255;
    }

    void helper(string s, int i, int part, string ans, vector<string> &res) {
        if (i == s.size() || part == 4) {
            if (i == s.size() && part == 4) {
                ans = ans.substr(0, ans.size() - 1);
                res.push_back(ans);
            }
            return;
        }

        helper(s, i + 1, part + 1, ans + s[i] + ".", res);

        string temp = s.substr(i, 2);
        if (i + 2 <= s.size() && isValid(temp))
            helper(s, i + 2, part + 1, ans + temp + ".", res);

        temp = s.substr(i, 3);
        if (i + 3 <= s.size() && isValid(temp))
            helper(s, i + 3, part + 1, ans + temp + ".", res);
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ans = "";
        helper(s, 0, 0, ans, res);
        return res;
    }
};

// https://leetcode.com/problems/restore-ip-addresses/
