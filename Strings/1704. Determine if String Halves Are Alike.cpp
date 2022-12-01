class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<int> st {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < s.size() / 2; i++) {
            if (st.find(s[i]) != st.end()) count1++;
        }
        for (int i = s.size() / 2; i < s.size(); i++) {
            if (st.find(s[i]) != st.end()) count2++;
        }
        return count1 == count2;
    }
};

// https://leetcode.com/problems/determine-if-string-halves-are-alike/