class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int i = 0, iceCreams = 0;

        while (costs[i] <= coins) {
            iceCreams++;
            coins -= costs[i];
            i++;
        }

        return iceCreams;
    }
};

// https://leetcode.com/problems/maximum-ice-cream-bars/