class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> directions{{ -1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int m = grid.size(), n = grid[0].size(), steps = 0;

        bool visited[m][n][k + 1];
        memset(visited, false, sizeof(visited));

        queue<vector<int>> q;
        q.push({0, 0, k});

        visited[0][0][k] = true;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto p = q.front();
                q.pop();

                if (p[0] == m - 1 && p[1] == n - 1) return steps;

                for (auto x : directions) {
                    int i = p[0] + x[0];
                    int j = p[1] + x[1];
                    int obstacle = p[2];

                    if (i >= 0 && i < m && j >= 0 && j < n) {
                        if (grid[i][j] == 0 && !visited[i][j][obstacle])  {
                            q.push({i, j, obstacle});
                            visited[i][j][obstacle] = true;
                        } else if (grid[i][j] == 1 && obstacle > 0 && !visited[i][j][obstacle - 1]) {
                            q.push({i, j, obstacle - 1});
                            visited[i][j][obstacle - 1] = true;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/