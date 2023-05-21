class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(int i, int j, vector<vector<int>> &grid, queue<pair<int, int>> &q, vector<vector<bool>> &vis) {
        vis[i][j] = true;
        q.push({i, j});

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x < 0 || y < 0 || x >= grid.size() || y >= grid.size() || vis[x][y] == true || grid[x][y] == 0)
                continue;

            dfs(x, y, grid, q, vis);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        bool flag = false;

        for (int i = 0; i < n && !flag; i++)
            for (int j = 0; j < n && !flag; j++)
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, q, vis);
                    flag = true;
                }

        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                pair<int, int> f = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int x = f.first + dx[k];
                    int y = f.second + dy[k];

                    if (x < 0 || y < 0 || x >= n || y >= n || vis[x][y] == true)    continue;

                    if (grid[x][y] == 1)    return level;

                    q.push({x, y});
                    vis[x][y] = true;
                }
            }

            level++;
        }

        return -1;
    }
};


// https://leetcode.com/problems/shortest-bridge/