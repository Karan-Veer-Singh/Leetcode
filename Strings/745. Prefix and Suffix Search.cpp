/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

class WordFilter {
private:
    unordered_map<string, int> mp;
public:
    WordFilter(vector<string>& words) {
        for (int index = 0; index < words.size(); index++) {
            string word = words[index];
            int len = word.size();

            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    string prefix = word.substr(0, len - i);
                    string suffix = word.substr(j);
                    mp[prefix + "#" + suffix] = index;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string s = prefix + "#" + suffix;
        if (mp.find(s) != mp.end())  return mp[s];
        return -1;
    }
};

/*
Time Complexity : O(NxW^2)
Space Complexity : O(NxW^2)
N: Number of word in words
W: Size of a word
*/

// https://leetcode.com/problems/prefix-and-suffix-search/