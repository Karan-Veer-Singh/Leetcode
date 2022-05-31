class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k)    return false;
        unordered_set<string> Set;
        for (int i = 0; i <= s.size() - k; i++)
            Set.insert(s.substr(i, k));
        return Set.size() == pow(2, k);
    }
};

// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/