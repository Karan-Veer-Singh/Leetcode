class Solution {
public:

    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }

        int ans = 0;

        for (auto w : words) {
            int prev = -1;
            for (int i = 0; i < w.size(); i++) {
                int idx = upper_bound(mp[w[i]].begin(), mp[w[i]].end(), prev) - mp[w[i]].begin();

                if (idx == mp[w[i]].size()) // goes out of bound
                    break;

                prev = mp[w[i]][idx];
                if (i == w.size() - 1) ans++;
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/number-of-matching-subsequences/