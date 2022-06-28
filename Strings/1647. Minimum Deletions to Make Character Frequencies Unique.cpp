class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (char ch : s)    freq[ch - 'a']++;
        sort(freq.begin(), freq.end(), greater<int>());
        int f = freq[0], ans = 0;
        for (int i : freq) {
            if (i > f) {
                if (f > 0)   ans += (i - f);
                else    ans += i;
            }
            f = min(f - 1, i - 1);
        }
        return ans;
    }
};

// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/