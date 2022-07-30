class Solution {
private:
    bool subset(vector<int> &source, vector<int> &dest) {
        for (int i = 0; i < 26; i++)
            if (dest[i] > source[i]) return false;

        return true;
    }

public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> target(26, 0);

        for (string s : words2) {
            vector<int> temp(26, 0);
            for (char ch : s) {
                temp[ch - 'a']++;
                target[ch - 'a'] = max(temp[ch - 'a'], target[ch - 'a']);
            }
        }

        for (string s : words1) {
            vector<int> temp(26, 0);
            for (char ch : s) temp[ch - 'a']++;
            if (subset(temp, target))    result.push_back(s);
        }

        return result;
    }
};

// https://leetcode.com/problems/word-subsets/