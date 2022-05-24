// TC-> O(N)    SC->O(N)

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxi = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                st.pop();
                if (st.empty()) st.push(i);
                else maxi = max(maxi, i - st.top());
            }
        }
        return maxi;
    }
};

------------------------------------------------------
// TC-> O(N)    SC-> O(1)

class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, res = 0;
        // forward traverse:
        for (auto ch : s) {
            if (ch == '(') open++;
            else close++;
            if (open == close) res = max(res, open + close);
            else if (close > open) open = close = 0;
        }
        open = close = 0;
        // backward traverse:
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') open++;
            else close++;
            if (open == close) res = max(res, open + close);
            else if (open > close) open = close = 0;
        }
        return res;
    }
};

// https://leetcode.com/problems/longest-valid-parentheses/submissions/