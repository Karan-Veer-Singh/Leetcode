/* If k is 1 then new column is (j+1) and if k is k then new column is (j+k) and new column should in range [0,m-1]. So new column is (j+k)%m.

For row, we have to first the find number of rows added to previous row which is equal to the number of times (j+k) exceeds m. So, number of rows added is (j+k)/m.

So, new row is (i + (j+k)/m) and new row should in range [0,n-1]. So new column is (i + (j+k)/m)%n. */

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int newJ = (j + k) % m;     // (j + numbers of columns added)%m
                int newI = (i + (j + k) / m) % n; // (i + numbers of rows added)%n
                ans[newI][newJ] = grid[i][j];
            }
        }
        return ans;

    }
};

// https://leetcode.com/problems/shift-2d-grid/submissions/