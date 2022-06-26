class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lSum = 0, rSum = 0, ans = 0;

        for (int i = 0; i < k; i++) lSum += cardPoints[i];

        ans = lSum;
        for (int i = 0; i < k; i++) {
            lSum -= cardPoints[k - i - 1];
            rSum += cardPoints[n - i - 1];
            ans = max(ans, lSum + rSum);
        }

        return ans;
    }
};

// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/