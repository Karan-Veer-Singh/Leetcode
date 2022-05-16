class Solution {
    int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
    int dy[8] = { -1, 1, 0, 0, -1, 1, 1, -1};

    bool isSafe(int x, int y, int &n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
        if (n == 1 && grid[0][0] == 0) return 1;
        queue<pair<int, pair<int, int>>> q;
        grid[0][0] = 1;
        q.push({1, {0, 0}});
        while (!q.empty()) {
            int dist = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int x = r + dx[i], y = c + dy[i];
                if (isSafe(x, y, n) && grid[x][y] == 0) {
                    if (x == n - 1 && y == n - 1) return dist + 1;
                    grid[x][y] = 1;
                    q.push({dist + 1, {x, y}});
                }
            }
        }
        return -1;
    }
};

// https://leetcode.com/problems/shortest-path-in-binary-matrix/