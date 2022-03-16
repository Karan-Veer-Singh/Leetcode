class Solution {
public:
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};

	void markBoundary(vector<vector<int>> &grid, int row, int col, int val)
	{
		grid[row][col] = -val;
		int cnt = 0;

		for (int i = 0; i < 4; i++)
		{
			int x = row + dx[i];
			int y = col + dy[i];

			if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || abs(grid[x][y]) != val) continue;

			cnt++;

			if (grid[x][y] == val)  markBoundary(grid, x, y, val);
		}

		if (cnt == 4) grid[row][col] = val;
	}

	void colorBoundary(vector<vector<int>> &grid, int color)
	{
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				if (grid[i][j] < 0)
					grid[i][j] = color;
	}

	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color)
	{
		markBoundary(grid, row, col, grid[row][col]);
		colorBoundary(grid, color);
		return grid;
	}
};

// https://leetcode.com/problems/coloring-a-border/submissions/