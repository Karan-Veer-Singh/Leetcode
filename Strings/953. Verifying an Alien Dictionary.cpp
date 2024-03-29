class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> m(26, 0);
        for (int i = 0; i < order.length(); i++)
            m[order[i] - 'a'] = i;

        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (j >= words[i + 1].size()) return false;

                if (words[i][j] != words[i + 1][j]) {
                    int curr = words[i][j] - 'a';
                    int next = words[i + 1][j] - 'a';
                    if (m[curr] > m[next]) return false;
                    else break;
                }
            }
        }
        return true;
    }
};

// https://leetcode.com/problems/verifying-an-alien-dictionary/