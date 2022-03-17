class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    q.push({i, j});

        if (q.size() == 0 || q.size() == n * n)  return -1;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int level = -1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                pair<int, int> f = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int x = f.first + dx[i];
                    int y = f.second + dy[i];

                    if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] == 1)   continue;

                    grid[x][y] = 1;
                    q.push({x, y});
                }
            }
            level++;
        }

        return level;
    }
};

// https://leetcode.com/problems/as-far-from-land-as-possible/submissions/