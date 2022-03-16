class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        if (grid.empty())    return 0;

        int m = grid.size(), n = grid[0].size();
        int days = 0, total = 0, rotten = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) total++;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }

        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty())
        {
            int k = q.size();
            rotten += k;

            while (k--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1) continue;

                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }

            if (!q.empty())  days++;
        }

        return total == rotten ? days : -1;
    }
};

// https://leetcode.com/problems/rotting-oranges/submissions/