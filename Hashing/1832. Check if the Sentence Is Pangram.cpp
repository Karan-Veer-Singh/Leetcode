class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> present(26, false);

        for (char ch : sentence)
            present[ch - 'a'] = true;

        for (bool res : present)
            if (res == false)
                return false;

        return true;
    }
};

// https://leetcode.com/problems/check-if-the-sentence-is-pangram/