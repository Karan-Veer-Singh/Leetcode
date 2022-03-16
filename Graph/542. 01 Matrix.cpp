class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int row = mat.size();
        int col = mat[0].size();

        queue<pair<int, int>> q;

        int dx[] = { -1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (mat[i][j] == 0)  q.push({i, j});
                else    mat[i][j] = -1;

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = curr.first + dx[i];
                int y = curr.second + dy[i];

                if (x >= 0 && y >= 0 && x < row && y < col && mat[x][y] < 0)
                {
                    mat[x][y] = mat[curr.first][curr.second] + 1;
                    q.push({x, y});
                }
            }
        }

        return mat;
    }
};

// https://leetcode.com/problems/01-matrix/submissions/