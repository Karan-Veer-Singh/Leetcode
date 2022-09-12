class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0, ans = 0, i = 0, j = tokens.size() - 1;
        while (i <= j) {
            if (tokens[i] <= power) {
                power -= tokens[i];
                score++;
                ans = max(ans, score);
                i++;
            }
            else if (score > 0) {
                power += tokens[j];
                score--;
                j--;
            }
            else    break;
        }
        return ans;
    }
};

// https://leetcode.com/problems/bag-of-tokens/