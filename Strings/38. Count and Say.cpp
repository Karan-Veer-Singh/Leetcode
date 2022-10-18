// Recursive
--------------

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)  return "1";

        string s = countAndSay(n - 1);
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            int count = 1;
            while (i < (s.size() - 1) and (s[i] == s[i + 1])) {
                i++;
                count++;
            }
            ans.append(to_string(count) + s[i]);
        }

        return ans;
    }
};
----------------------------------------------------------------------------------

// Iterative
--------------

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for (int k = 2; k <= n; k++) {
            string temp = "";
            for (int i = 0; i < ans.size(); i++) {
                int count = 1;
                while (i < (ans.size() - 1) and (ans[i] == ans[i + 1])) {
                    i++;
                    count++;
                }
                temp.append(to_string(count) + ans[i]);
            }
            ans = temp;
        }

        return ans;
    }
};