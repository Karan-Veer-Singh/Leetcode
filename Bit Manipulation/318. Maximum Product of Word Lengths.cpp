class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0);

        for (int i = 0; i < n; ++i) {
            int num = 0;
            for (int j = 0; j < words[i].size(); ++j) {
                num |= 1 << (words[i][j] - 'a');
            }
            mask[i] = num;
        }

        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((mask[i]&mask[j]) == 0) {
                    int prod = words[i].size() * words[j].size();
                    res = max(res, prod);
                }
            }
        }

        return res;
    }
};

// TC - O(N^2)

/*
   |= is bitwise OR operator...
   1 << (words[i][j]-'a') appends 0s to the end of 1...
   for ex: a becomes 1, b becomes 10, c becomes 100 and so on...
   and if our string is ab, then the w_bin we get is 1|10 which is 11.
*/