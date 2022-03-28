class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());

        if (s.find(endWord) == s.end())  return 0;

        queue<string> q;
        q.push(beginWord);
        int noOfWords = 0;

        while (!q.empty()) {
            int size = q.size();
            noOfWords++;

            while (size--) {
                string currWord = q.front(); q.pop();

                for (int i = 0; i < currWord.size(); i++) {
                    string temp = currWord;

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        temp[i] = ch;

                        if (temp.compare(currWord) == 0)  continue;
                        if (temp.compare(endWord) == 0)   return noOfWords + 1;

                        if (s.find(temp) != s.end()) {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }

        return 0;
    }
};

// https://leetcode.com/problems/word-ladder/submissions/