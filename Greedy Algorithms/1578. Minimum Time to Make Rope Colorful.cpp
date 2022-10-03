class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), gsum = 0, gmax = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && colors[i] != colors[i - 1]) {
                ans += (gsum - gmax);
                gsum = 0;
                gmax = 0;
            }
            gsum += neededTime[i];
            gmax = max(gmax, neededTime[i]);
        }
        ans += (gsum - gmax);
        return ans;
    }
};

// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/