class Solution {
private:
    int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size(), c = board[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x >= 0 && x < r && y >= 0 && y < c && (board[x][y] == 1 || board[x][y] == 2)) {
                        count++;
                    }
                }

                if (board[i][j] == 1) {
                    if (count < 2 || count > 3)  board[i][j] = 2;
                }
                else {
                    if (count == 3)  board[i][j] = 3;
                }
            }
        }

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                board[i][j] = board[i][j] % 2;

    }
};

// https://leetcode.com/problems/game-of-life/