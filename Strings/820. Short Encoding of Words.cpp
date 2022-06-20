class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());

        for (string str : words)
            for (int i = 1; i < str.size(); i++)
                st.erase(str.substr(i));

        int count = 0;
        for (string str : st)    count += str.size() + 1;

        return count;
    }
};

// https://leetcode.com/problems/short-encoding-of-words/