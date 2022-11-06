class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            int n = s.size();
            string temp = s + s;
            string ans = s;

            for (int i = 0; i < n; i++) {
                string sub = temp.substr(i, n);
                if (sub < ans) ans = sub;
            }
            return ans;
        }

        sort(s.begin(), s.end());
        return s;
    }
};

// https://leetcode.com/problems/orderly-queue/