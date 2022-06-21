class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(), bricksUsed = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i - 1];
            if (diff > 0)    pq.push(diff);
            if (pq.size() > ladders) {bricksUsed += pq.top(); pq.pop();}
            if (bricksUsed > bricks) return i - 1;
        }

        return n - 1;
    }
};

// https://leetcode.com/problems/furthest-building-you-can-reach/