class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
        vector<int> ans(2, 0);

        int n = a.size(), x = 0;

        for (int i = 0; i < n; i++) x ^= a[i];

        for (int i = 1; i <= n; i++)    x ^= i;

        int rsb = x & -x;
        int c = 0, d = 0;

        for (int i = 0; i < n; i++)
            if ((a[i] & rsb) == 0)  c ^= a[i];
            else    d ^= a[i];

        for (int i = 1; i <= n; i++)
            if ((i & rsb) == 0) c ^= i;
            else    d ^= i;

        for (int i = 0; i < n; i++) {
            if (a[i] == c) {
                ans[0] = c;
                ans[1] = d;
                break;
            }
            else if (a[i] == d) {
                ans[0] = d;
                ans[1] = c;
                break;
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/set-mismatch/