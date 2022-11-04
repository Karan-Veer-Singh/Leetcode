class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'
               || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    }
public:
    string reverseVowels(string s) {
        int start = 0;
        int end  = s.size() - 1;

        while (start < end) {
            while (start < end && !isVowel(s[start])) start++;
            while (start < end && !isVowel(s[end])) end--;
            swap(s[start++], s[end--]);
        }
        return s;
    }
};

// https://leetcode.com/problems/reverse-vowels-of-a-string/description/