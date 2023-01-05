class Solution {
private:
    bool static compare(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);

        int end = points[0][1];
        int arrows = 1;

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > end) {
                end = points[i][1];
                arrows++;
            }
        }

        return arrows;
    }
};

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/