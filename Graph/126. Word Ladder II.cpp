class Solution {
public:
    void dfs(string beginWord, string endWord, unordered_map<string, vector<string>> &adj, vector<string> &path, vector<vector<string>> &ans) {
        path.push_back(beginWord);
        if (beginWord == endWord) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for (auto ngbr : adj[beginWord])
            dfs(ngbr, endWord, adj, path, ans);

        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> level;
        unordered_set<string> s(wordList.begin(), wordList.end());

        vector<vector<string>> ans;
        vector<string> path;

        if (s.find(endWord) == s.end())  return ans;

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        while (!q.empty()) {
            string curr = q.front(); q.pop();

            for (int i = 0; i < curr.size(); i++) {
                string temp = curr;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (temp == curr)    continue;

                    if (s.find(temp) != s.end()) {
                        if (level.find(temp) != level.end()) {
                            level[temp] = level[curr] + 1;
                            q.push(temp);
                            adj[curr].push_back(temp);
                        }
                        else if (level[temp] == level[curr] + 1) {
                            adj[curr].push_back(temp);
                        }
                    }
                }
            }
        }

        dfs(beginWord, endWord, adj, path, ans);
        return ans;
    }
};

// https://leetcode.com/problems/word-ladder-ii/