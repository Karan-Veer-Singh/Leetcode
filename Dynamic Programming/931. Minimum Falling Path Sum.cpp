class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0), curr(n, 0);

        for (int col = 0; col < n; col++)    prev[col] = matrix[0][col];

        for (int row = 1; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int up = matrix[row][col] + prev[col];

                int leftDiag = matrix[row][col];
                leftDiag += (col - 1 >= 0) ? prev[col - 1] : 1e8;

                int rightDiag = matrix[row][col];
                rightDiag += (col + 1 < n) ? prev[col + 1] : 1e8;

                curr[col] = min({up, leftDiag, rightDiag});
            }
            prev = curr;
        }

        int ans = INT_MAX;
        for (int col = 0; col < n; col++)
            ans = min(ans, prev[col]);

        return ans;
    }
};

// https://leetcode.com/problems/minimum-falling-path-sum/