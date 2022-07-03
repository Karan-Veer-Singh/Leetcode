class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int hl = horizontalCuts.size(); int vl = verticalCuts.size();

        int maxHeight = max(horizontalCuts[0], h - horizontalCuts[hl - 1]);
        for (int i = 1; i < hl; i++) {
            int horizontalHeight = horizontalCuts[i] - horizontalCuts[i - 1];
            maxHeight = max(maxHeight, horizontalHeight);
        }

        int maxWidth = max(verticalCuts[0], w - verticalCuts[vl - 1]);
        for (int i = 1; i < vl; i++) {
            int verticalHeight = verticalCuts[i] - verticalCuts[i - 1];
            maxWidth = max(maxWidth, verticalHeight);
        }

        long long ans = 1L * maxHeight * maxWidth;
        return (int)(ans % 1000000007);
    }
};

// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/