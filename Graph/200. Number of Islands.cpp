class Solution {
public:
    void connectComponents(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j)
    {
        // Boundary Conditions
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' || vis[i][j] == true)
            return;

        // mark the current land as visited
        vis[i][j] = true;

        connectComponents(grid, vis, i - 1, j); // TOP
        connectComponents(grid, vis, i + 1, j); // DOWN
        connectComponents(grid, vis, i, j - 1); // LEFT
        connectComponents(grid, vis, i, j + 1); // RIGHT
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int count = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1' && vis[i][j] == false)
                {
                    connectComponents(grid, vis, i, j);
                    count++;
                }

        return count;
    }
};


// Without using visited array..

class Solution {
public:
    // 0 -> water, 1 -> unvisited land, 2 -> visited land

    void connectComponents(vector<vector<char>> &grid, int i, int j)
    {
        // Boundary Conditions
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
            return;

        // mark the current land as visited
        grid[i][j] = '2';

        connectComponents(grid, i - 1, j);  // TOP
        connectComponents(grid, i + 1, j);  // DOWN
        connectComponents(grid, i, j - 1);  // LEFT
        connectComponents(grid, i, j + 1);  // RIGHT
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1')
                {
                    connectComponents(grid, i, j);
                    count++;
                }

        return count;
    }
};