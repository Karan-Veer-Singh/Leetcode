class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<string> q;
        unordered_map<string, bool> vis;
        string target = "123450";
        string str = "";

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                str += to_string(board[i][j]);

        vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

        q.push(str);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string temp = q.front();
                q.pop();

                if (temp == target) return level;

                int index = -1;
                for (int i = 0; i < temp.size(); i++)
                    if (temp[i] == '0') {
                        index = i;
                        break;
                    }

                vector<int> pos = dir[index];
                for (int i = 0; i < pos.size(); i++) {
                    string n = temp;
                    swap(n[index], n[pos[i]]);

                    if (vis.find(n) != vis.end())   continue;

                    q.push(n);
                    vis[n] = true;
                }
            }
            level++;
        }
        return -1;
    }
};

// https://leetcode.com/problems/sliding-puzzle/