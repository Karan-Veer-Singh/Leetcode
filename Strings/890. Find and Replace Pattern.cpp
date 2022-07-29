class Solution {
private:
    bool match(string &word, string &pattern) {
        unordered_map<char, char> wmp;
        unordered_map<char, char> pmp;

        for (int i = 0; i < word.size(); i++) {
            char w = word[i];
            char p = pattern[i];

            if (wmp.find(w) == wmp.end())    wmp[w] = p;
            if (pmp.find(p) == pmp.end())    pmp[p] = w;
            if (wmp[w] != p || pmp[p] != w)  return false;
        }
        return true;
    }

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (string word : words)
            if (match(word, pattern))
                ans.push_back(word);

        return ans;
    }
};

// https://leetcode.com/problems/find-and-replace-pattern/