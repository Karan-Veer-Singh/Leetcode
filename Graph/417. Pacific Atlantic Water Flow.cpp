class Solution {
public:

    void dfs(vector<vector<int>> &matrix, int i, int j, int prev, vector<vector<int>> &ocean)
    {
        if (i < 0 || i >= ocean.size() || j < 0 || j >= ocean[0].size())
            return;

        if (matrix[i][j] < prev || ocean[i][j])
            return;

        ocean[i][j] = 1;

        dfs(matrix, i + 1, j, matrix[i][j], ocean);
        dfs(matrix, i, j + 1, matrix[i][j], ocean);
        dfs(matrix, i - 1, j, matrix[i][j], ocean);
        dfs(matrix, i, j - 1, matrix[i][j], ocean);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
    {
        vector<vector<int>> ans;
        if (matrix.size() < 1)
            return ans;

        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> pacific(row, vector<int>(col, 0));
        vector<vector<int>> atlantic(row, vector<int>(col, 0));

        for (int i = 0; i < col; i++)
        {
            dfs(matrix, 0, i, INT_MIN, pacific);
            dfs(matrix, row - 1, i, INT_MIN, atlantic);
        }

        for (int i = 0; i < row; i++)
        {
            dfs(matrix, i, 0, INT_MIN, pacific);
            dfs(matrix, i, col - 1, INT_MIN, atlantic);
        }

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (atlantic[i][j] && pacific[i][j])
                {
                    vector<int> v(2);
                    v[0] = i;
                    v[1] = j;
                    ans.push_back(v);
                }

        return ans;
    }
};

// https://leetcode.com/problems/pacific-atlantic-water-flow/
