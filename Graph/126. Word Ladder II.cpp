class Solution {
public:
    bool able(string s, string t) {
        if (s.length() != t.length())
            return false;
        int c = 0;
        for (int i = 0; i < s.length(); i++)
            c += (s[i] != t[i]);
        return c == 1;
    }
    void bfs(vector<vector<int>> &g, vector<int> parent[], int n, int sr, int ds) {
        vector <int> dist(n, 1005);
        queue <int> q;
        q.push(sr);
        parent[sr] = { -1};
        dist[sr] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int u : g[x]) {
                if (dist[u] > dist[x] + 1) {
                    dist[u] = dist[x] + 1;
                    q.push(u);
                    parent[u].clear();
                    parent[u].push_back(x);
                }
                else if (dist[u] == dist[x] + 1)
                    parent[u].push_back(x);
            }
        }
    }
    void shortestPaths(vector<vector<int>> &Paths, vector<int> &path, vector<int> parent[], int node) {
        if (node == -1) {
            Paths.push_back(path);
            return ;
        }
        for (auto u : parent[node]) {
            path.push_back(u);
            shortestPaths(Paths, path, parent, u);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), sr = -1, ds = -1;
        vector<vector<string>> ANS;
        for (int i = 0; i < n; i++) {
            if (wordList[i] == beginWord)
                sr = i;
            if (wordList[i] == endWord)
                ds = i;
        }
        if (ds == -1)
            return ANS;
        if (sr == -1) {
            wordList.emplace(wordList.begin(), beginWord);
            sr = 0;
            ds++;
            n++;
        }
        vector <vector<int>> g(n, vector<int>()), Paths;
        vector <int> parent[n], path;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (able(wordList[i], wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
        bfs(g, parent, n, sr, ds);
        shortestPaths(Paths, path, parent, ds);
        for (auto u : Paths) {
            vector <string> now;
            for (int i = 0; i < u.size() - 1; i++)
                now.push_back(wordList[u[i]]);
            reverse(now.begin(), now.end());
            now.push_back(wordList[ds]);
            ANS.push_back(now);
        }
        return ANS;
    }
};
------------------------------------------------------------------------------------

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