class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.length(), k, l;

        for (k = len - 2; k >= 0; k--)
            if (s[k] < s[k + 1])   break;

        if (k < 0)   return -1;

        for (l = len - 1; l > k; l--)
            if (s[l] > s[k]) break;

        swap(s[k], s[l]);
        reverse(s.begin() + k + 1, s.end());

        long long int ans = stoll(s);
        return ans > INT_MAX ? -1 : ans;
    }
};

// https://leetcode.com/problems/next-greater-element-iii/submissions/