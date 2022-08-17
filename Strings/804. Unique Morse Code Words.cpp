class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> s;

        for (string word : words) {
            string temp = "";
            for (char ch : word) {
                temp += code[ch - 'a'];
            }
            s.insert(temp);
        }
        return (s.size());
    }
};

// https://leetcode.com/problems/unique-morse-code-words/