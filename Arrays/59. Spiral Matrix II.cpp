class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n,  0));
        int t = 0, b = n - 1;
        int l = 0, r = n - 1;
        int dir = 0;
        int val =  1;

        while (l <= r && t <= b) {
            if (dir == 0) {
                for (int i = l; i <= r; i++)
                    v[t][i] = val++;
                t++;
            }
            else if (dir == 1) {
                for (int i = t; i <= b; i++)
                    v[i][r] = val++;
                r--;
            }
            else if (dir == 2) {
                for (int i = r; i >= l; i--)
                    v[b][i] = val++;
                b--;
            }
            else if (dir == 3) {
                for (int i = b; i >= t; i--)
                    v[i][l] = val++;
                l++;
            }

            dir = (dir + 1) % 4;
        }

        return v;
    }
};

// https://leetcode.com/problems/spiral-matrix-ii/