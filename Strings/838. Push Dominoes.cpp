class Solution {
private:
    void solve(string &temp, int j, int k) {
        for (int i = j + 1; i < k; i++) {
            if (temp[j] == 'L' && temp[k] == 'L') {
                temp[i] = 'L';
            }
            else if (temp[j] == 'R' && temp[k] == 'R') {
                temp[i] = 'R';
            }
            else if (temp[j] == 'L' && temp[k] == 'R') {
                continue;
            }
            else if (temp[j] == 'R' && temp[k] == 'L') {
                int diff = k - j - 1;
                int mid = (j + k) / 2;

                if (diff % 2 == 0) {
                    if (i <= mid)        temp[i] = 'R';
                    else if (i > mid)    temp[i] = 'L';
                }
                else {
                    if (i < mid)         temp[i] = 'R';
                    else if (i > mid)    temp[i] = 'L';
                }
            }
        }
    }

public:
    string pushDominoes(string dominoes) {
        string temp = "L";
        for (char c : dominoes)  temp += c;
        temp += 'R';

        int j = 0, k = 1;
        while (k < temp.size()) {
            while (temp[k] == '.')    k++;
            solve(temp, j, k);
            j = k;
            k++;
        }

        string ans = "";
        for (int i = 1; i < temp.size() - 1; i++)
            ans += temp[i];

        return ans;
    }
};

// https://leetcode.com/problems/push-dominoes/