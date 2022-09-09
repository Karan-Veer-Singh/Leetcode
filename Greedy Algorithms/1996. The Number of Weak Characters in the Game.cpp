class Solution {
private:
    bool static compare(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), compare);
        int weakCount = 0, maxDefense = INT_MIN;
        for (int i = 0; i < properties.size(); i++) {
            if (properties[i][1] < maxDefense)   weakCount++;
            if (properties[i][1] > maxDefense)   maxDefense = properties[i][1];
        }
        return weakCount;
    }
};

// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/