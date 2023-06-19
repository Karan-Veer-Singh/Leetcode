class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highestAltitude = 0;
        int altitude = 0;

        for (int i : gain) {
            altitude += i;
            highestAltitude = max(altitude, highestAltitude);
        }

        return highestAltitude;
    }
};

// https://leetcode.com/problems/find-the-highest-altitude/