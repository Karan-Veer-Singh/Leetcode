class Solution {
private:
    void countSort(vector<vector<int>> &mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        int i = r, j = c;
        vector<int> freq(101, 0);

        while (i < m && j < n) {
            freq[mat[i][j]]++;
            i++; j++;
        }

        i = r, j = c;
        for (int k = 1; k < freq.size(); k++) {
            while (freq[k] > 0) {
                mat[i][j] = k;
                freq[k]--;
                i++; j++;
            }
        }
    }

public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        for (int i = 0; i < r; i++)  countSort(mat, i, 0);
        for (int j = 1; j < c; j++)  countSort(mat, 0, j);
        return mat;
    }
};

// https://leetcode.com/problems/sort-the-matrix-diagonally/