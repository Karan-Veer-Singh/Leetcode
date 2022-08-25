class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> freq;
        for (char ch : magazine) freq[ch]++;
        for (char ch : ransomNote)   freq[ch]--;
        for (auto it : freq)
            if (it.second < 0)   return false;

        return true;
    }
};

// https://leetcode.com/problems/ransom-note/