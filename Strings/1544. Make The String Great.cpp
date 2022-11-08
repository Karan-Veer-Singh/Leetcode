class Solution {
public:
    string makeGood(string s) {
        string ans;

        for (int i = 0; i < s.size(); i++) {
            ans.push_back(s[i]);

            while (ans.size() && abs(ans.back() - s[i + 1]) == 32) {
                ans.pop_back();
                i++;
            }
        }

        return ans;
    }
};

// TC- O(N)
// SC- O(1)
___________________________________________________________________

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for (char &ch : s) {
            if (!st.empty() && abs(st.top() - ch) == 32)
                st.pop();
            else
                st.push(ch);
        }

        string ans;
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};

// TC- O(N)
// SC- O(N)

// https://leetcode.com/problems/make-the-string-great/